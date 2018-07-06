#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListADT.h"
#include "AirportADT.h"
#include "Types.h"
#include "MovementADT.h"
#include "ProcessData.h"
#include "errorHandler.h"

//	Constants Definitions
//  Movement Constants
#define MAX_TEXT_MOVEMENT 150
//  --------------  Named Fields
#define ARRIVAL "Aterrizaje"
#define DEPARTURE "Despegue"
#define INTERNATIONAL "Internacional"
#define LOCAL "Cabotaje"

//  Airport Constants
#define MAX_TEXT_AIRPORT 300
//  --------------  Named Fields
#define NATIONAL "Nacional"

//	Function Prototypes
int movementsProcessing (ListADT airportList, int yearGiven, int * movPerDay, int * dayCode, int * monthCode, int * yearcode);

int
main (int argc, char *argv[]){

    TErrors errorType = NO_ERROR;

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
			errorType = ARG_OUTOF_RANGE;
		}

	} else if (argc > 2){
		errorType = MANY_ARGS;
	} else {
		errorType = FEW_ARGS;
	}

	//  After the argument is received, it verifies whether or not it produced an error
	verifyErrorType(errorType);

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
 *	Function to process all data from the flights file
 *	Return Values:	0 - if everything works
 *					1 - if there was an error while trying to open the file
 */
TErrors
movementsProcessing (ListADT airportList, int yearGiven, int * movPerDay, int * dayCode, int * monthCode, int * yearcode){

    //  File opening and verification
    //  ------------------------------------------------------------------------------------------
	FILE * movementsFile;
	
	movementsFile = fopen("Dataset/archivoVuelos.csv", "r");
	if (movementsFile == NULL){
		printf("ERROR: El archivo archivoVuelos.csv no pudo ser abierto.\n");
		return CANT_OPEN_MOV;
	}
    //  ------------------------------------------------------------------------------------------

	char fileLine[MAX_TEXT_MOVEMENT];
	char separator[] = ";";
	char tokens[10][30];
	char * token;
	int counter;

	/*
	 * We are interested in tokens with indexes 0 / 3 / 4 / 5 / 6
	 * 		Token 0 :	Movement date
	 * 		Token 3 :	Flight type (internacional o nacional)
	 * 		Token 4 :	Flight classification (aterrizaje o despegue)
	 * 		Token 5 :	Origin OACI
	 * 		Token 6 :	Destination OACI
	 */

	//	We discard the first line of the file for being the names of the fields
	fgets(fileLine, MAX_TEXT_MOVEMENT, movementsFile);

	//  Iterating for each line in the file
	while (fgets(fileLine, MAX_TEXT_MOVEMENT, movementsFile) != NULL){

	    counter = 0;
        token = strtok(fileLine, separator);

        //  If the year is correct, it runs this
        if (verifyYear(tokens[M_DATE], yearGiven)){

            //  Makes the change to day of the week and increments the counter for that day
            movPerDay[dateToDayOfWeek(tokens[M_DATE], dayCode, monthCode, yearcode)]++;

            //  It gets the rest of the tokens from that line
            while( token != NULL ) {

                strcpy(tokens[counter++], token);

            	//	We use NULL inside strtok for it to continue where it finished the previous iteration
                token = strtok(NULL, separator);
            }

			MovementADT auxMovement;
			AirportADT auxAirport;
			bool isLocal = !strcmp(tokens[M_TYPE], LOCAL);
			bool isDeparture = !strcmp(tokens[M_CLASS], DEPARTURE);

            //	Checks if the movement is a departure
            if (!(strcmp(tokens[M_CLASS], DEPARTURE))){

                //  If the OACI code from the departure airport is unknown, we skip it
                if (!(isUnknownOACI(tokens[ORIG]))){

                    //  If the OACI code form the arrival airport is unknown, we cant add it to the list, but the movement counts
                    if (!(isUnknownOACI(tokens[M_DESTIN]))) {

                        //	Auxiliary airport and movement
                        auxAirport = (AirportADT) getElem(airportList, tokens[ORIG]);
                        auxMovement = getMovement(auxAirport, tokens[M_DESTIN]);

                        //	If the pointer is NULL, it means there is no previous movement with that airport
                        if (auxMovement == NULL) {

                            //	It creates a new movement, increases the counter and adds it to the airport
                            auxMovement = newMovement(tokens[M_DESTIN], isLocal);
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
                if (!(isUnknownOACI(tokens[M_DESTIN]))) {

                    //  If the OACI code form the departure airport is unknown, we cant add it to the list, but the movement counts
                    if (!(isUnknownOACI(tokens[ORIG]))) {

                        auxAirport = (AirportADT) getElem(airportList, tokens[M_DESTIN]);
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

TErrors
airportProcessing (){

	//  File opening and verification
	//  ------------------------------------------------------------------------------------------
	FILE * airportsFile;

	airportsFile = fopen("Dataset/archivoAeropuertos.csv", "r");
	if (airportsFile == NULL){
		printf("ERROR: El archivo archivoAeropuertos.csv no pudo ser abierto.\n");
		// TODO SACAR EL MENSAJE DE ERROR ESTE, Y HACER UN ARRAY CON TODOS LOS ERRORES PARA ORDENAR MEJOR
		return CANT_OPEN_AIRP;
	}
	//  ------------------------------------------------------------------------------------------

	char fileLine[MAX_TEXT_AIRPORT];
	char separator = ';';
	char * tokens[23];

	/*
	 * We are interested in tokens with indexes 0 / 1 / 2 / 4 / 18
	 * 		Token 0 :	Local Code
	 * 		Token 1 :	OACI Code
	 * 		Token 2 :	IATA Code
	 * 		Token 4 :	Denomination
	 * 		Token 18 :	Traffic Type (Nacional o Internacional)
	 */

	//	 We discard the first line because it has the field names.
	fgets(fileLine, MAX_TEXT_MOVEMENT, airportsFile);

	//  Iterating for each line in the file
	while (fgets(fileLine, MAX_TEXT_MOVEMENT, airportsFile) != NULL){

		//	We separate the line extracted into all the tokes, knowing the ones we want
		separateToken(fileLine, separator, tokens, 23);

		//	If the OACI code for that airport is blank (length 0 / it contains only a 0), it is not going to have recorded movements, so we don't care about it.
		if (tokens[1][0] != 0){

            bool isNational = !strcmp(tokens[A_TYPE], NATIONAL);

			//TODO USAR FUNCION PARA AGREGAR UN AEROPUERTO NUEVO

		}
	}





}
