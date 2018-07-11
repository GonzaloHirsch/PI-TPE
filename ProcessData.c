#include "ProcessData.h"
#include "ADT/AirportADT.h"
#include "Types.h"
#include "ADT/MovementADT.h"
#include "ErrorHandler.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

///     ---------- FUNCTIONS  ----------

size_t
separateToken(char *str, char del, char ** strArr, size_t dim) {

    if(dim <= 0) {
        return 0;
    }

    *strArr = str;

    int i = 0;

    while (str[i] != del && str[i] != 0){
        i++;
    }
    if(str[i] == del){
        str[i] = 0;
        return 1 + separateToken(str + i + 1, del, strArr + 1, dim - 1);
    } else {
        return 1;
    }

}

int
isUnknownOACI(const char * airportOACI){

    int formatA, formatB, aux;

    //  In case the OACI has the format SA##
    formatA = sscanf(airportOACI, "SA%2d", &aux);

    //  In case the OACI has more/less than 4 characters
    formatB = strlen(airportOACI) != 4;

    return formatA || formatB;

}

int
dateToDayOfWeek (const char * date, int * dayCode, int * monthCode, int * yearCode){

    int day, month, year, specialMonthCode;

    //  Separating the date
    getDate(date, &day, &month, &year);

    //  If it is a leap year, the month codes change for the first two
    if (year == 2016 && (month == 1 || month == 2))
        specialMonthCode = monthCode[month - 1] - 1;
    else
        specialMonthCode = monthCode[month - 1];

    int dayOfWeekIndex = dayCode[day % 7] + specialMonthCode + yearCode[year - 2014];

    //  Using "%7" because the index has to be between 0 and 6
    return dayOfWeekIndex % 7;

}

void
getDate (const char * date, int * day, int * month, int * year){

    sscanf(date, "%2d/%2d/%4d", day, month, year);

}

int
verifyYear (const char * date, int yearGiven){

    int year;

    //  The * are used to ignore the fields that don't matter to us
    sscanf(date, "%*d/%*d/%4d", &year);

    return year == yearGiven;

}

int
verifyString (const char * str){

    size_t length = strlen(str);
    int i;

    //  It's a flag, if type is 1 the string is only numbers, else it's a 0.
    int type = 1;

    for (i = 0; i < length && type; i++){

        if (!isdigit(str[i]))
            type = 0;

    }

    return type;
}

TErrors
movementsProcessing (AirportList airportList, int yearGiven, int * movPerDay, int * dayCode, int * monthCode, int * yearCode){

    ///     ---------- FILE OPENING AND VERIFICATION ----------

    FILE * movementsFile;

    movementsFile = fopen("Datasets/archivoVuelos.csv", "r");

    //  If the file couldn't be opened, the pointer is NULL
    if (movementsFile == NULL)
        return CANT_OPEN_MOV;

    ///     ---------- MOVEMENT PROCESSING ----------

    char fileLine[MAX_TEXT_MOVEMENT];
    char separator = ';';
    char * tokens[10];

    //	We discard the first line of the file for being the names of the fields
    fgets(fileLine, MAX_TEXT_MOVEMENT, movementsFile);

    //  Iterating for each line in the file
    while (fgets(fileLine, MAX_TEXT_MOVEMENT, movementsFile) != NULL){

        //	It separates the line into the tokens
        separateToken(fileLine, separator, tokens, 10);

        //  If the year is correct, it runs this
        if (verifyYear(tokens[M_DATE], yearGiven)){

            //  Makes the change to day of the week and increments the counter for that day
            movPerDay[dateToDayOfWeek(tokens[M_DATE], dayCode, monthCode, yearCode)]++;

            AirportADT auxAirport;
            bool isLocal = !strcmp(tokens[M_TYPE], M_LOCAL);
            bool isDeparture = !strcmp(tokens[M_CLASS], M_DEPARTURE);
            bool isOriginKnown = !(isUnknownOACI(tokens[M_ORIGIN]));
            bool isDestinKnown = !(isUnknownOACI(tokens[M_DESTIN]));

            //  All these verifications are needed in order to be able to store the data and to make sense of the file

            //	Checks if the movement is a departure
            if (isDeparture){

                //	It gets the airport with the specified OACI code
                auxAirport = getAirportElem(airportList, tokens[M_ORIGIN]);

                //  If the OACI code from the departure airport is unknown, or if it's not in the airports file, we skip it
                if (isOriginKnown && auxAirport != NULL)
                    if (addMovement(auxAirport, tokens[M_DESTIN], isDestinKnown, isLocal, isDeparture) == false)    //It verifies the was space to allocate memory
                        return NO_MEM_TO_ALLOC;

            } else {	//This is if the movement is an arrival

                //	It gets the airport with the specified OACI code
                auxAirport = getAirportElem(airportList, tokens[M_DESTIN]);

                //  If the OACI code from the arrival airport is unknown, or if it's not in the airports file, we skip it
                if (isDestinKnown && auxAirport != NULL)
                    if (addMovement(auxAirport, tokens[M_ORIGIN], isOriginKnown, isLocal, isDeparture) == false)    //It verifies the was space to allocate memory
                        return NO_MEM_TO_ALLOC;
            }
        }
    }
    fclose(movementsFile);
    return NO_ERROR;
}

TErrors
airportProcessing (AirportList airportList){

    ///     ---------- FILE OPENING AND VERIFICATION ----------

    FILE * airportsFile;

    airportsFile = fopen("Datasets/archivoAeropuertos.csv", "r");

    //  If the file couldn't be opened, the pointer is NULL
    if (airportsFile == NULL)
        return CANT_OPEN_AIRP;

    ///     ---------- AIRPORT PROCESSING ----------

    char fileLine[MAX_TEXT_AIRPORT];
    char separator = ';';
    char * tokens[23];

    //	 We discard the first line because it has the field names.
    fgets(fileLine, MAX_TEXT_AIRPORT, airportsFile);

    //  Iterating for each line in the file
    while (fgets(fileLine, MAX_TEXT_AIRPORT, airportsFile) != NULL){

        //	We separate the line extracted into all the tokes, knowing the ones we want
        separateToken(fileLine, separator, tokens, 23);

        /*
         * If the OACI code for that airport is blank (length 0 / it contains only a 0),
         * it is not going to have recorded movements, so we don't care about it.
         */
        if (!isUnknownOACI(tokens[A_OACI]))
            if (addAirport(airportList, tokens[A_OACI], tokens[A_LOCAL], tokens[A_IATA], tokens[A_DENOM]) == false)  //It verifies the was space to allocate memory
                return NO_MEM_TO_ALLOC;
    }
    fclose(airportsFile);
    return NO_ERROR;
}

///     ---------- ----------