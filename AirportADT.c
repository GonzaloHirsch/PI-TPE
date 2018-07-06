#include <stdlib.h>
#include "AirportADT.h"
#include "ListADT.h"
#include <string.h>

typedef struct AirportCDT {
    tLocal local;
    tOACI oaci;
    tIATA iata;
    Denomination denomination;
    TTraffic traffic;
    MovementList movements;
    int unknownDepartures;
    int unknownArrivals;
 } AirportCDT;

 AirportADT newAirport(OACI oaci){
 	AirportADT retVal = malloc(sizeof(AirportCDT));
 	strcpy(retVal->oaci, oaci);
 	retVal->movements =  newMovementList();         //funcion de MovementADT.h
 	retVal->unknownArrivals = retVal->unknownDepartures = 0;
 	return retVal;
 }

 void setIATA(AirportADT airport, IATA iata){
 	strcpy(airport->iata, iata);
 }

 void setDenomination(AirportADT airport, Denomination denomination){
 	strcpy(airport->denomination, iata);
 }

 void setTraffic(AirportADT airport, TTraffic traffic){
 	airport->traffic = traffic;
 }

 OACI getAirportOACI(AirportADT airport){
 	return airport->oaci;
 }

 void addMovement(AirportADT airport, MovementADT movement){
 	addMovementElem(airport->movements, movement);                         //funcion de listADT.h
 }

MovementADT getMovement(AirportADT airport, OACI oaci){
	return getMovementElem(airport->movements, oaci);                       //funcion de listADT.h
}

//////////////////////// LIST FUNCTIONS BELOW

AirportList newAirportList(){
	return newList( (OACI (*) (void *)) getAirportOACI);
}

void addAirportElem(AirportList list, AirportADT elem){
	addElem(list,elem);
}

AirportADT getAirportElem(AirportList list, OACI oaci){
	return getElem(list,oaci);
}