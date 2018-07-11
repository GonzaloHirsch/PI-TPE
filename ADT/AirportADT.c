///     ---------- INCLUDES ----------

#include <stdlib.h>
#include "AirportADT.h"
#include "ListADT.h"
#include <string.h>
#include "../ProcessData.h"

///     ---------- TYPEDEFS ----------

typedef struct AirportCDT {
    tLocal local;
    tOACI oaci;
    tIATA iata;
    tDenomination denomination;
    MovementList movements;
    int totalMovements;
    int internationalArrivals;
    int internationalDepartures;
    int unknownDepartures;
    int unknownArrivals;
 } AirportCDT;

///     ---------- FUNCTIONS ----------

 AirportADT newAirport(OACI oaci, IATA iata, Local local, Denomination denomination){
 	AirportADT retVal = malloc(sizeof(AirportCDT));

    //  If there is no space, it returns NULL
    if (retVal == NULL) {
        return retVal;
    }

 	strcpy(retVal->oaci, oaci);
 	strcpy(retVal->local, local);
 	strcpy(retVal->iata, iata);
 	strcpy(retVal->denomination, denomination);

 	MovementList movementAux = newMovementList();

     //  If there is no space, it returns NULL
 	if (movementAux == NULL)
 	    return NULL;

 	retVal->movements = movementAux;
 	retVal->unknownArrivals = retVal->unknownDepartures = retVal->totalMovements = retVal->internationalDepartures = retVal->internationalArrivals = 0;
 	return retVal;
 }

bool addMovement(AirportADT airport, OACI oaci, bool isOaciKnown, bool isNational, bool isDeparture){

    if(isOaciKnown) {

        MovementADT movement = getMovementElem(airport->movements, oaci);
        if (movement == NULL) {
            movement = newMovement(oaci);
            if (addMovementElem(airport->movements, movement) == 2)
                return false;
        }

        if (isDeparture) {
            addDeparture(movement, 1);
        } else {
            addArrival(movement, 1);
        }

    } else {

        if(isDeparture)
            airport->unknownDepartures++;
        else
            airport->unknownArrivals++;

    }

    if(!isNational) {
        if (isDeparture) {
            airport->internationalDepartures++;
        } else {
            airport->internationalArrivals++;
        }
    }

    airport->totalMovements++;
    return true;
}

bool addAirport (AirportList airportList, OACI oaci, Local local, IATA iata, Denomination denomination){

    //  Creates a new airport with all the data
    AirportADT airportAux = newAirport(oaci, iata, local, denomination);

    //  If there is no space it returns NULL
    if (airportAux == NULL)
        return false;

    // Adds the airport to the list;
    int wasAdded = addElem(airportList, airportAux);

    //  If there is no space it returns NULL
    if (wasAdded == 2)
        return false;

    //	If it can't add the airport, it frees it
    if (!wasAdded)
        freeAirportADT(airportAux);
    return true;
}

void freeAirportADT(AirportADT airport) {
    freeListADT(airport -> movements);
    free(airport);
}
///     ---------- SETTERS & GETTERS ----------
/*
 * Setters & Getters are used in order to facilitate any future modifications to any specific Airport.
 */

OACI getAirportOACI(AirportADT airport){
 	return airport->oaci;
}

Local getAirportLocal(AirportADT airport){
    return airport->local;
}

Denomination getAirportDenomination(AirportADT airport){
    return airport->denomination;
}

int getAirportTotalMovements(AirportADT airport){
    return airport->totalMovements;
}

int getAirportInternationalArrivals(AirportADT airport){
    return airport->internationalArrivals;
}

int getAirportUnknownDepartures(AirportADT airport){
    return airport->unknownDepartures;
}

int getAirportUnknownArrivals(AirportADT airport){
    return airport->unknownArrivals;
}

int getAirportInternationalDepartures(AirportADT airport){
    return airport->internationalDepartures;
}

IATA getAirportIATA(AirportADT airport){
    return airport->iata;
}

MovementList getMovementList(AirportADT airport){
     return airport->movements;
 }

///     ---------- LIST FUNCTIONS ----------

AirportList newAirportList(){
	return newList((OACI (*) (void *)) getAirportOACI, (void (*)(void *)) freeAirportADT);
}

AirportADT getAirportElem(AirportList list, OACI oaci){
	return getElem(list,oaci);
}

///     ---------- ----------