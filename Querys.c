#include "ADT/AirportADT.h"
#include "ADT/MovementADT.h"
#include <stdio.h>
#include "ErrorHandler.h"

///     ---------- FUNCTIONS ----------

void
Query1(FILE * file, AirportADT airport){

    int totalMovements = getAirportTotalMovements(airport);

    if (totalMovements != 0)
        fprintf(file, "%s;%s;%s;%d\n", getAirportOACI(airport), getAirportLocal(airport), getAirportDenomination(airport), totalMovements);

}

void
Query2(FILE * file, AirportADT airport){

    int internationalTotal = getAirportInternationalDepartures(airport) + getAirportInternationalArrivals(airport);

    if (internationalTotal != 0)
        fprintf(file, "%s;%s;%d;%d;%d\n", getAirportOACI(airport), getAirportIATA(airport), getAirportInternationalDepartures(airport), getAirportInternationalArrivals(airport), internationalTotal);

}

void
Query3(FILE * file, int * movPerDay){

    char * days[7] = {"Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado", "Domingo"};

    /*
     * Prints each day with the corresponding amount of movements
     * We use ((i + 1) % 7) as an index because the first day in movPerDay is Sunday,
     * so we have to start in 1 and the last one to be 0.
     */
    for (int i = 0; i < 7; i++)
        fprintf(file, "%s;%d\n", days[i], movPerDay[(i + 1) % 7]);
}

void
Query4(FILE * file, AirportADT airport){

    //  Gets the movements list from the given airport
    MovementList movementList = getMovementList(airport);

    toStart(movementList);

    int unknownDepartures = getAirportUnknownDepartures(airport), unknownArrivals = getAirportUnknownArrivals(airport);

    //  The unknown movements are first in alphabetic order
    if (unknownArrivals != 0 || unknownDepartures != 0)
        fprintf(file, "%s;;%d;%d\n", getAirportOACI(airport), unknownDepartures, unknownArrivals);

    while(hasNext(movementList)){

        MovementADT movement = getNextMovement(movementList);

        //  Prints the movements with each airport on the movements list
        fprintf(file, "%s;%s;%d;%d\n", getAirportOACI(airport), getMovementOACI(movement), getDepartures(movement), getArrivals(movement));

    }
}

TErrors
QueryProcessing(AirportList airportList, int * movPerDay){

    //  Creates the files for the queries
    FILE * fileQuery1 = fopen("movs_aeropuerto.csv", "w");
    FILE * fileQuery2 = fopen("movs_international.csv", "w");
    FILE * fileQuery3 = fopen("semanal.csv", "w");
    FILE * fileQuery4 = fopen("aerop_detalle.csv", "w");

    //  If the file couldn't be opened/created, the pointer is NULL
    if (fileQuery3 != NULL)
        Query3(fileQuery3, movPerDay);

    toStart(airportList);

    while(hasNext(airportList)){

        AirportADT airport = getNextAirport(airportList);

        //  If the file couldn't be opened/created, the pointer is NULL
        if (fileQuery1 != NULL)
            Query1(fileQuery1, airport);
        if (fileQuery2 != NULL)
            Query2(fileQuery2, airport);
        if (fileQuery4 != NULL)
            Query4(fileQuery4, airport);
    }

    fclose(fileQuery4);
    fclose(fileQuery3);
    fclose(fileQuery2);
    fclose(fileQuery1);

    //  In case any of the files couldn't be opened/created
    if (fileQuery1 == NULL || fileQuery2 == NULL || fileQuery3 == NULL || fileQuery4 == NULL)
        return CANT_CREATE_FILE;

    return NO_ERROR;
}

///     ---------- ----------