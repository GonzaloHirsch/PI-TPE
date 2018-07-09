#include "ADT/AirportADT.h"
#include <stdio.h>
#include "ErrorHandler.h"

TErrors
Query1and2(AirportList airportList){

    //  Creates new files for writing
    FILE * newFileQ1 = fopen("movs_aeropuerto.csv", "w");
    FILE * newFileQ2 = fopen("movs_international.csv", "w");

    //  If the pointer is NULL, it means it couldn't create it
    if (newFileQ1 == NULL || newFileQ2 == NULL)
        return CANT_CREATE_FILE;


    ///     ------------    Iterating through each airport in the list  ------------

    toStart(airportList);

    while(hasNext(airportList)){

        AirportADT airport = (AirportADT) getNext(airportList);

        int internationalTotal = getAirportInternationalDepartures(airport) + getAirportInternationalArrivals(airport);
        int totalMovements = getAirportTotalMovements(airport);

        //  Prints to the new file for query 1
        if (totalMovements != 0)
            fprintf(newFileQ1, "%s;%s;%s;%d\n", getAirportOACI(airport), getAirportLocal(airport), getAirportDenomination(airport), totalMovements);

        //  Prints to the new file for query 2
        if (internationalTotal != 0)
            fprintf(newFileQ2, "%s;%s;%d;%d;%d\n", getAirportOACI(airport), getAirportIATA(airport), getAirportInternationalDepartures(airport), getAirportInternationalArrivals(airport), internationalTotal);
    }

    ///     ------------------------

    fclose(newFileQ2);
    fclose(newFileQ1);
    return NO_ERROR;
}

TErrors
Query3(int * movPerDay){

    //  Creates a new file for writing
    FILE * newFile = fopen("semanal.csv", "w");

    //  If the pointer is NULL, it means it couldn't create it
    if (newFile == NULL)
        return CANT_CREATE_FILE;

    char * days[7] = {"Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado", "Domingo"};

    /*
     * Prints each day with the corresponding amount of movements
     * We use ((i + 1) % 7) as an index because the first day in movPerDay is Sunday,
     * so we have to start in 1 and the last one to be 0.
     */
    for (int i = 0; i < 7; i++)
        fprintf(newFile, "%s;%d\n", days[i], movPerDay[(i + 1) % 7]);

    fclose(newFile);
    return NO_ERROR;
}

TErrors
Query4(AirportList airportList){

    //  Creates a new file for writing
    FILE * newFile = fopen("aerop_detalle.csv", "w");

    //  If the pointer is NULL, it means it couldn't create it
    if (newFile == NULL)
        return CANT_CREATE_FILE;

    ///     ------------    Iterating through each airport in the list  ------------

    toStart(airportList);

    while(hasNext(airportList)){

        AirportADT airport = (AirportADT) getNext(airportList);

        if (getAirportTotalMovements(airport) != 0){

            MovementList movementList = getMovementList(airport);

            toStart(movementList);

            int unknownDepartures = getAirportUnknownDepartures(airport), unknownArrivals = getAirportUnknownArrivals(airport);

            if (unknownArrivals != 0 || unknownDepartures != 0)
                fprintf(newFile, "%s;;%d;%d\n", getAirportOACI(airport), unknownDepartures, unknownArrivals);

            while(hasNext(movementList)){

                MovementADT movement = (MovementADT) getNext(movementList);

                //  Prints the line to the file
                fprintf(newFile, "%s;%s;%d;%d\n", getAirportOACI(airport), getMovementOACI(movement), getDepartures(movement), getArrivals(movement));

            }
        }
    }

    ///     ------------------------

    fclose(newFile);
    return NO_ERROR;
}