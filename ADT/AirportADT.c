#include <stdlib.h>
#include "AirportADT.h"
#include "ListADT.h"
#include <string.h>
#include "ProcessData.h"

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

 AirportADT newAirport(OACI oaci){
 	AirportADT retVal = malloc(sizeof(AirportCDT));
 	strcpy(retVal->oaci, oaci);
 	retVal->movements =  newMovementList();
 	retVal -> unknownArrivals = retVal -> unknownDepartures = 0;
 	return retVal;
 }

/// ---- SETTERS & GETTERS ----
/*
 * Setters & Getters are used in order to facilitate any future modifications to any specific Airport.
 */


 void setLocalCode(AirportADT airport, Local local){
     strcpy(airport -> local, local);
 }

 void setIATA(AirportADT airport, IATA iata){
 	strcpy(airport->iata, iata);
 }

 void setDenomination(AirportADT airport, Denomination denomination){
 	strcpy(airport->denomination, denomination);
 }

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

/// ---- ----

void addUnknownDeparture (AirportADT airport, int amount){
    airport->unknownDepartures += amount;
}

void addUnknownArrival (AirportADT airport, int amount){
    airport->unknownArrivals += amount;
}

void addInternationalArrival (AirportADT airport, int amount){ // TODO BORRAR
    airport->internationalArrivals += amount;
}

void addInternationalDeparture (AirportADT airport, int amount){ // TODO BORRAR
    airport->internationalDepartures += amount;
}

void addTotalMovement (AirportADT airport, int amount){ // TODO BORRAR
    airport->totalMovements += amount;
}

bool incrementMovement(AirportADT airport, TMovement movType, bool isOaciKnown, OACI oaci) {
    if(isOaciKnown) {
        MovementADT movement = getMovementElem(airport->movements, oaci);
        if (movement != NULL) {
            airport->totalMovements++;
            if(movType == DEPARTURE) {
                addDeparture(movement, 1);
                airport->internationalDepartures += !isMovementNational(movement) ;
            } else {
                addArrival(movement, 1);
                airport->internationalArrivals += !isMovementNational(movement);
            }
            return true;
        } else
            return false;
    }
    else {
        airport->unknownDepartures++;
        airport->totalMovements++;
        return true;
    };
}

 void addMovement(AirportADT airport, MovementADT movement, TMovement movType){
     addMovementElem(airport->movements, movement);
     airport->totalMovements++;
     if(movType == ARRIVAL){
         airport->internationalArrivals += !isMovementNational(movement);
         addArrival(movement,1);
     } else{
         airport->internationalDepartures += !isMovementNational(movement);
         addDeparture(movement,1);
     }

 }

MovementADT getMovement(AirportADT airport, OACI oaci){ // TODO: BORRAR
	return getMovementElem(airport->movements, oaci);
}


void freeAirportADT(AirportADT airport) {
     freeListADT(airport -> movements);
     free(airport);
}


/// --- LIST FUNCTIONS ---

AirportList newAirportList(){
	return newList((OACI (*) (void *)) getAirportOACI, (void (*)(void *)) freeAirportADT);
}

void addAirportElem(AirportList list, AirportADT elem){
	addElem(list,elem);
}

AirportADT getAirportElem(AirportList list, OACI oaci){
	return getElem(list,oaci);
}

/// --- ---