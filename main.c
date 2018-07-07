#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ADT/ListADT.h"
#include "ADT/AirportADT.h"
#include "Types.h"
#include "ADT/MovementADT.h"
#include "ProcessData.h"
#include "ErrorHandler.h"

int
main (int argc, char *argv[]){

    TErrors errorType = NO_ERROR;

	// It receives the year as an argument and checks whether or not it is valid, if not, it shows an error message and aborts
	int yearGiven;
	int year;

	//	If only one argument is passed, argc is 2, because there is argv[0]
	if (argc == 2){

	    if (verifyString(argv[1])){

            //	The index is 1, because argv[0] has the file name
            sscanf(argv[1], "%d", &year);

            if (2014 <= year && year <= 2018)
                yearGiven = year;
            else {
                errorType = ARG_OUTOF_RANGE;
            }

	    } else
	        errorType = ARG_NOT_YEAR;

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



	//TODO crear una lista vacia para los aeropuertos
	//TODO llamar a las funciones que procesan
	//TODO despues de cada proceso, verificar que no haya habido ningun error

}
