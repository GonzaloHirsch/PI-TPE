#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListADT.h"
#include "AirportADT.h"
#include "Types.h"
#include "MovementADT.h"

//	Constants Definitions
#define MAX_TEXT 150
#define FDATE 0
#define FTYPE 3
#define FCLASS 4
#define ORIG 5
#define DEST 6
#define ARRIVAL "Aterrizaje"
#define DEPARTURE "Despegue"
#define INTERNATIONAL "Internacional"
#define LOCAL "Cabotaje"

//	Function Prototypes
int verifyYear (const char * date, int yearGiven);
void getDate (const char * date, int * day, int * month, int * year);
int dateToDayOfWeek (const char * date, int * dayCode, int * monthCode, int * yearCode);
int isUnknownOACI(const char * airportOACI);
int movementsProcessing (ListADT airportList, int yearGiven, int * movPerDay, int * dayCode, int * monthCode, int * yearcode);


int
main (int argc, char *argv[]){

	// It receives the year as an argument and checks whether or not it is valid, if not, it shows an error message and aborts
	int yearGiven;
	int year;

	//	If only one argument is passed, argc is 2, because there is argv[0]
	if (argc == 2){

		//	The index is 1, because argv[0] has the file name
		sscanf(argv[1], "%d", &year);

		if (2014 <= year && year <= 2018)
			yearGiven = year;
		else {
			printf("ERROR: El año tiene que estar entre 2014 y 2018.\n");
			exit(1);
		}

	} else if (argc > 2){
		printf("ERROR: Fueron ingresados demasiados argumentos.\n");
		exit(1);
	} else {
		printf("ERROR: Se espera un argumento.\n");
		exit(1);
	}

	/*
	 *	Ammount of movements per day of the week
	 *	Index:	Domingo = 0 , Lunes = 1 , ... , Sabado = 6
	 */
	int movPerDay[7] = {0};

	/*
	 *	Day codes for the conversion from date to day of the week
	 *	Index:	Domingo = 0 , Lunes = 1 , ... , Sabado = 6
	 */
	int dayCode[7] = {0, 1, 2, 3, 4, 5, 6};
	/*
	 *	Day codes for the conversion from date to day of the week
	 *	Index:	Enero = 0 , Febrero = 1 , ... , Diciembre = 11
	 */
	int monthCode[12] = {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	/*
	 *	Day codes for the conversion from date to day of the week
	 *	Index:	2014 = 0 , 2015 = 1 , ... , 2018 = 4
	 */
	int yearCode[5] = {3, 4, 6, 0, 1};

}


/*
 * 	Verifies whether or not the year it receives is the year we want
 * 	Return values:	0 - If its not the year we want
 * 					1 - If it is the year we want
 */
int
verifyYear (const char * date, int yearGiven){

	int year;

	int args = sscanf(date, "%*d/%*d/%4d", &year);

	return year == yearGiven;
}

/*
 * 	Extracts the day, month and year from a given date
 */
void
getDate (const char * date, int * day, int * month, int * year){

	int args = sscanf(date, "%2d/%2d/%4d", day, month, year);
	return;
}

/*
 * 	Given a date, it calculates the day of the week
 * 	Return value:	Integer representing the day of the week for the array movPerDay[]
 */
int
dateToDayOfWeek (const char * date, int * dayCode, int * monthCode, int * yearCode){

	int day, month, year;
	getDate(date, &day, &month, &year);

	int dayOfWeekIndex = dayCode[day % 7] + monthCode[month - 1] + yearCode[year - 2014];

	return dayOfWeekIndex % 7;
}

/*
 *  Verifies whether or not the OACI code from the airport is unknown
 *  Unknown OACI codes have this layout (x is a digit):
 *      SAxx
 *      AR-xxxx
 *  Return values:  0 - if OACI is KNOWN
 *                  1 - if OACI is UNKNOWN
 */
int
isUnknownOACI(const char * airportOACI){
    int formatA, formatB;
    int aux;

    formatA = sscanf(airportOACI, "SA%2d", &aux);
    formatB = sscanf(airportOACI, "AR-%4d", &aux);

    return formatA || formatB;
}

/*
 *	Function to process all data from the flights file
 *	Return Values:	0 - if everything works
 *					1 - if there was an error while trying to open the file
 */
int
movementsProcessing (ListADT airportList, int yearGiven, int * movPerDay, int * dayCode, int * monthCode, int * yearcode){

    //  File opening and verification
    //  ------------------------------------------------------------------------------------------
	FILE * movementsFile;
	
	movementsFile = fopen("Dataset/archivoVuelos.csv", "r");
	if (movementsFile == NULL){
		printf("ERROR: El archivo archivoVuelos.csv no pudo ser abierto.\n");
		return 1;
	}
    //  ------------------------------------------------------------------------------------------

	char fileLine[MAX_TEXT];
	char separator[2] = ";";
	char * tokens[10];
	int counter;

	/*
	 * We are interested in tokens with indexes 0 / 3 / 4 / 5 / 6
	 * 		Token 0 :	Movement date
	 * 		Token 3 :	Flight type (internacional o nacional)
	 * 		Token 4 :	Flight classification (aterrizaje o despegue)
	 * 		Token 5 :	Origin OACI
	 * 		Toekn 6 :	Destination OACI
	 */

	//	We discard the first line of the file for being the names of the fields
	fgets(fileLine, MAX_TEXT, movementsFile);

	//  Iterating for each line in the file
	while (fgets(fileLine, MAX_TEXT, movementsFile) != NULL){

	    counter = 0;
        tokens[counter] = strtok(fileLine, separator);

        //  If the year is correct, it runs this
        if (verifyYear(tokens[FDATE], yearGiven)){

            //  Makes the change to day of the week and increments the counter for that day
            movPerDay[dateToDayOfWeek(tokens[FDATE], dayCode, monthCode, yearcode)]++;

            //  It gets the rest of the tokens from that line
            while( tokens[counter] != NULL ) {
            	//	We use NULL inside strtok for it to continue where it finished the previous iteration
                tokens[++counter] = strtok(NULL, fileLine);
            }

			MovementADT auxMovement;
			AirportADT auxAirport;
			bool isLocal = !strcmp(tokens[FTYPE], LOCAL);

            //	Checks if the movement is a departure
            if (!(strcmp(tokens[FCLASS], DEPARTURE))){

                //  If the OACI code from the departure airport is unknown, we skip it
                if (!(isUnknownOACI(tokens[ORIG]))){

                    //  If the OACI code form the arrival airport is unknown, we cant add it to the list, but the movement counts
                    if (!(isUnknownOACI(tokens[DEST]))) {

                        //	Auxiliary airport and movement
                        auxAirport = (AirportADT) getElem(airportList, tokens[ORIG]);
                        auxMovement = getMovement(auxAirport, tokens[DEST]);

                        //	If the pointer is NULL, it means there is no previous movement with that airport
                        if (auxMovement == NULL) {

                            //	It creates a new movement, increases the counter and adds it to the airport
                            auxMovement = newMovement(tokens[DEST], isLocal);
                            addDeparture(auxMovement, 1);
                            addMovement(auxAirport, auxMovement);

                        } else {
                            addDeparture(auxMovement, 1);
                        }
                    }
                }
                //TODO incrementar el contador total en 1 (no necesito un else, lo voy a hacer igual)
            } else {	//	This is if the movement is a arrival

                //  If the OACI code from the arrival airport is unknown, we skip it
                if (!(isUnknownOACI(tokens[DEST]))) {

                    //  If the OACI code form the departure airport is unknown, we cant add it to the list, but the movement counts
                    if (!(isUnknownOACI(tokens[ORIG]))) {

                        auxAirport = (AirportADT) getElem(airportList, tokens[DEST]);
                        auxMovement = getMovement(auxAirport, tokens[ORIG]);

                        //	If the pointer is NULL, it means there is no previous movement with that airport
                        if (auxMovement == NULL) {

                            //	It creates a new movement, increases the counter and adds it to the airport
                            auxMovement = newMovement(tokens[ORIG], isLocal);
                            addArrival(auxMovement, 1);
                            addMovement(auxAirport, auxMovement);

                        } else {
                            addArrival(auxMovement, 1);
                        }
                    }
                    //TODO incrementar el contador total en 1 (no necesito un else, lo voy a hacer igual)
                }
            }
        }
	}
	fclose(movementsFile);
	return 0;
}
