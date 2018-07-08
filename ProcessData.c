#include "ProcessData.h"
#include "ADT/AirportADT.h"
#include "Types.h"
#include "ADT/MovementADT.h"
#include "ErrorHandler.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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

    int formatA, formatB, formatC, formatD;
    int aux;
    char auxStr;

    formatA = sscanf(airportOACI, "SA%2d", &aux);
    formatB = sscanf(airportOACI, "AR-%4d", &aux);
    formatC = sscanf(airportOACI, "N/%1s", &auxStr);
    formatD = strlen(airportOACI) > 4;

    return formatA || formatB || formatC || formatD;

}

int
dateToDayOfWeek (const char * date, int * dayCode, int * monthCode, int * yearCode){

    int day, month, year;
    getDate(date, &day, &month, &year);

    int dayOfWeekIndex = dayCode[day % 7] + monthCode[month - 1] + yearCode[year - 2014];

    return dayOfWeekIndex % 7;

}

void
getDate (const char * date, int * day, int * month, int * year){

    sscanf(date, "%2d/%2d/%4d", day, month, year);

}

int
verifyYear (const char * date, int yearGiven){

    int year;

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

    //  File opening and verification
    //  ------------------------------------------------------------------------------------------
    FILE * movementsFile;

    movementsFile = fopen("Datasets/archivoVuelos.csv", "r");
    if (movementsFile == NULL)
        return CANT_OPEN_MOV;
    //  ------------------------------------------------------------------------------------------

    char fileLine[MAX_TEXT_MOVEMENT];
    char separator = ';';
    /*
    char tokens[10][30];
    char * token;
    int counter;
    */
    char * tokens[10];

    //	We discard the first line of the file for being the names of the fields
    fgets(fileLine, MAX_TEXT_MOVEMENT, movementsFile);

    //  Iterating for each line in the file
    while (fgets(fileLine, MAX_TEXT_MOVEMENT, movementsFile) != NULL){

        //	It separates the line into the tokens
        separateToken(fileLine, separator, tokens, 10);

        /*
        counter = 0;
        token = strtok(fileLine, separator);
        */

        //  If the year is correct, it runs this
        if (verifyYear(tokens[M_DATE], yearGiven)){

            //  Makes the change to day of the week and increments the counter for that day
            movPerDay[dateToDayOfWeek(tokens[M_DATE], dayCode, monthCode, yearCode)]++;

            /*
            //  It gets the rest of the tokens from that line
            while( token != NULL ) {

                strcpy(tokens[counter++], token);

            	//	We use NULL inside strtok for it to continue where it finished the previous iteration
                token = strtok(NULL, separator);
            }
            */

            MovementADT auxMovement;
            AirportADT auxAirport;
            bool isLocal = !strcmp(tokens[M_TYPE], M_LOCAL);
            bool isDeparture = !strcmp(tokens[M_CLASS], M_DEPARTURE);
            bool isOriginKnown = !(isUnknownOACI(tokens[M_ORIGIN]));
            bool isDestinKnown = !(isUnknownOACI(tokens[M_DESTIN]));

            //	Checks if the movement is a departure
            if (isDeparture){

                //	It gets the airport with the specified OACI code
                auxAirport = getAirportElem(airportList, tokens[M_ORIGIN]);

                //  If the OACI code from the departure airport is unknown, or if it's not in the airports file, we skip it
                if (isOriginKnown && auxAirport != NULL){

                    //  If the OACI code from the arrival airport is unknown, we can't add it to the list, but the movement counts
                    if (isDestinKnown) {

                        auxMovement = getMovement(auxAirport, tokens[M_DESTIN]);

                        //	If the pointer is NULL, it means there is no previous movement with that airport
                        if (auxMovement == NULL) {

                            //	It creates a new movement, increases the counter and adds it to the airport
                            auxMovement = newMovement(tokens[M_DESTIN], isLocal);
                            //	We can't increment outside the if statement because we have to do it before adding it to the list
                            addDeparture(auxMovement, 1);
                            addMovement(auxAirport, auxMovement);

                        } else {
                            addDeparture(auxMovement, 1);
                        }
                    } else {
                        //  Increases the unknown departures by 1.
                        addUnknownDeparture(auxAirport, 1);
                    }

                    //  Increases the international departure amount.
                    if (!isLocal)
                        addInternationalDeparture(auxAirport, 1);

                    //  Increases the total movement amount.
                    addTotalMovement(auxAirport, 1);
                }
            } else {	//	This is if the movement is an arrival

                //	It gets the airport with the specified OACI code
                auxAirport = getAirportElem(airportList, tokens[M_DESTIN]);

                //  If the OACI code from the arrival airport is unknown, or if it's not in the airports file, we skip it
                if (isDestinKnown && auxAirport != NULL) {

                    //  If the OACI code form the departure airport is unknown, we cant add it to the list, but the movement counts
                    if (isOriginKnown) {

                        auxMovement = getMovement(auxAirport, tokens[M_ORIGIN]);

                        //	If the pointer is NULL, it means there is no previous movement with that airport
                        if (auxMovement == NULL) {

                            //	It creates a new movement, increases the counter and adds it to the airport
                            auxMovement = newMovement(tokens[M_ORIGIN], isLocal);
                            //	We can't increment outside the if statement because we have to do it before adding it to the list
                            addArrival(auxMovement, 1);
                            addMovement(auxAirport, auxMovement);

                        } else {
                            addArrival(auxMovement, 1);
                        }
                    } else {
                        //  Increases the unknown arrivals counter by 1.
                        addUnknownArrival(auxAirport, 1);
                    }

                    //  Increases the international arrival amount.
                    if (!isLocal)
                        addInternationalArrival(auxAirport, 1);

                    //  Increases the total movement amount.
                    addTotalMovement(auxAirport, 1);
                }
            }
        }
    }
    fclose(movementsFile);
    return NO_ERROR;
}

TErrors
airportProcessing (AirportList airportList){

    //  File opening and verification
    //  ------------------------------------------------------------------------------------------
    FILE * movementsFile;

    movementsFile = fopen("Datasets/archivoAeropuertos.csv", "r");
    if (movementsFile == NULL)
        return CANT_OPEN_AIRP;
    //  ------------------------------------------------------------------------------------------

    char fileLine[MAX_TEXT_AIRPORT];
    char separator = ';';
    char * tokens[23];

    //	 We discard the first line because it has the field names.
    fgets(fileLine, MAX_TEXT_AIRPORT, movementsFile);

    //  Iterating for each line in the file
    while (fgets(fileLine, MAX_TEXT_AIRPORT, movementsFile) != NULL){

        //	We separate the line extracted into all the tokes, knowing the ones we want
        separateToken(fileLine, separator, tokens, 23);

        /*
         * If the OACI code for that airport is blank (length 0 / it contains only a 0),
         * it is not going to have recorded movements, so we don't care about it.
         */
        if (tokens[A_OACI][0] != 0){

            AirportADT airportAux = getAirportElem(airportList, tokens[A_OACI]);

            //	If there is no airport with that OACI code, it adds it to the airport list
            if (airportAux == NULL){

                bool isNational = !strcmp(tokens[A_TYPE], A_NATIONAL);

                //	Creating a new airport with all its fields complete
                airportAux = newAirport(tokens[A_OACI]);
                setLocalCode(airportAux, tokens[A_LOCAL]);
                setIATA(airportAux, tokens[A_IATA]);
                setDenomination(airportAux, tokens[A_DENOM]);
                setTraffic(airportAux, isNational ?  NATIONAL : INTERNATIONAL);

                //	Adds the new airport to the airport list
                addAirportElem(airportList, airportAux);

            }
        }
    }
    fclose(movementsFile);
    return NO_ERROR;
}
