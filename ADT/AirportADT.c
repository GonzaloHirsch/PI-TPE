#include <stdlib.h>
#include "AirportADT.h"
#include "ListADT.h"
#include <string.h>
#include "ProcessData.h"

typedef struct AirportCDT {
    tLocal local;
    tOACI oaci;
    tIATA iata;
    Denomination denomination;
    TTraffic traffic;
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
 	retVal->movements =  newMovementList(); //        funcion de MovementADT.h
 	retVal -> unknownArrivals = retVal -> unknownDepartures = 0;
 	return retVal;
 }

AirportADT newAirportFromTokens(char ** tokens) {
	AirportADT retVal = newAirport(tokens[A_OACI]);
	setLocalCode(retVal, tokens[A_LOCAL]);
	setIATA(retVal, tokens[A_IATA]);
	setDenomination(retVal, tokens[A_DENOM]);
	setTraffic(retVal, strcmp(tokens[A_TYPE], A_NATIONAL) ?  NATIONAL : INTERNATIONAL);
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

 void setTraffic(AirportADT airport, TTraffic traffic){
 	airport->traffic = traffic;
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

int getAirportInternationalDepartures(AirportADT airport){
    return airport->internationalDepartures;
}

IATA getAirportIATA(AirportADT airport){
    return airport->iata;
}

/// ---- ----

void addUnknownDeparture (AirportADT airport, int amount){
    airport->unknownDepartures += amount;
}

void addUnknownArrival (AirportADT airport, int amount){
    airport->unknownArrivals += amount;
}

void addInternationalArrival (AirportADT airport, int amount){
    airport->internationalArrivals += amount;
}

void addInternationalDeparture (AirportADT airport, int amount){
    airport->internationalDepartures += amount;
}

void addTotalMovement (AirportADT airport, int amount){
    airport->totalMovements += amount;
}

 void addMovement(AirportADT airport, MovementADT movement){
 	addMovementElem(airport->movements, movement);                         //funcion de listADT.h
 }

MovementADT getMovement(AirportADT airport, OACI oaci){ // TODO: SE PODRIA BORRAR ESTA FUNCION
	return getMovementElem(airport->movements, oaci);                       //funcion de listADT.h
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