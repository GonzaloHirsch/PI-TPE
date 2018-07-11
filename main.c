///     ---------- INCLUDES ----------

#include <stdio.h>
#include "ADT/AirportADT.h"
#include "ProcessData.h"
#include "ErrorHandler.h"
#include "Querys.h"

///     ---------- FUNCTION PROTOTYPES ----------

/*
 *	Verifies whether the input the user gave is valid or not.
 *	Parameters:
 *	    int argc --> The argument count the program gives after it starts
 *	    char ** argv --> The array of pointers to char the program gives after it starts
 *	    TErrors * errorType --> Pointer to error type, to know if there was an error when the user gave an argument
 *  Return value:
 *      If the year given by the user IS NOT VALID, it returns 0.
 *      If the year given by the user IS VALID, it returns that year.
 */
int verifyInput (int argc, char ** argv, TErrors * errorType);

///     ---------- PROGRAM MAIN  ----------

int
main (int argc, char * argv[]){

    TErrors errorType = NO_ERROR;

	// It receives the year as an argument and checks whether or not it is valid.
	int year = verifyInput(argc, argv, &errorType);

	/*
	 *	Amount of movements per day of the week.
	 *	Index:	Domingo = 0 , Lunes = 1 , ... , Sábado = 6
	 */
	int movPerDay[7] = {0};

	/*
	 *	Day codes for the conversion from date to day of the week.
	 *	Index:	Domingo = 0 , Lunes = 1 , ... , Sábado = 6
	 */
	int dayCode[7] = {0, 1, 2, 3, 4, 5, 6};
	/*
	 *	Day codes for the conversion from date to day of the week.
	 *	Index:	Enero = 0 , Febrero = 1 , ... , Diciembre = 11
	 */
	int monthCode[12] = {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	/*
	 *	Day codes for the conversion from date to day of the week.
	 *	Index:	2014 = 0 , 2015 = 1 , ... , 2018 = 4
	 */
	int yearCode[5] = {3, 4, 6, 0, 1};

	//	Creates the list containing all the airports.
	AirportList airportList = newAirportList();

	//  If there was no memory available to allocate, the pointer is going to be NULL.
	if (airportList == NULL)
	    errorType = NO_MEM_TO_ALLOC;

	//	Processes all airports.
	if (errorType == NO_ERROR)
        errorType = airportProcessing(airportList);

	//	Processes all movements.
	if (errorType == NO_ERROR)
		errorType = movementsProcessing(airportList, year, movPerDay, dayCode, monthCode, yearCode);

	//  Creates all queries
	if (errorType == NO_ERROR)
        errorType = QueryProcessing(airportList, movPerDay);

    //  Freeing all the resources
	freeListADT(airportList);

	//	Verify if there was an error during the whole execution and print a message according to it.
    verifyErrorType(errorType);

	return errorType;
}

///     ---------- FUNCTIONS ----------

int
verifyInput (int argc, char ** argv, TErrors * errorType){

    //  We give it 0 as a value just to have it initialized.
	int year = 0;

	//	If only one argument is passed, argc is 2, because there is argv[0].
	if (argc == 2){

        //  Verifies if the string is only digits
		if (verifyString(argv[1])){

			//	The index is 1, because argv[0] has the file name.
			sscanf(argv[1], "%d", &year);

			if (!(2014 <= year && year <= 2018))
				*errorType = ARG_OUTOF_RANGE;

		} else
			*errorType = ARG_NOT_YEAR;

	} else if (argc > 2){
		*errorType = MANY_ARGS;
	} else {
		*errorType = FEW_ARGS;
	}

	return year;
}

///     ---------- ----------