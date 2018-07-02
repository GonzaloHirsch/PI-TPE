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
    ListADT movements;
 } AirportCDT;

OACI getAirportOACI(AirportADT airport){
 	return airport->oaci;
 }

 AirportADT newAirport(OACI oaci){
 	AirportADT retVal = malloc(sizeof(AirportCDT));
 	strcpy(retVal->oaci, oaci);
 	retVal->movements = newList(getMovementOACI(MovementADT));         //funcion de MovementADT.h
 	return retVal;
 }

 void setIATA(AirportADT airport, IATA iata){
 	strcpy(airport->iata, iata);
 }
/*
 void setDenomination(AirportADT airport, Denomination denomination){
 	Lo dejé vacío  porque para mí descripción debería ser char*. Sino se complican los prints
 }

*/

 void setTraffic(AirportADT airport, TTraffic traffic){
 	airport->traffic = traffic;
 }

 void addMovement(AirportADT airport, MovementADT movement){
 	addElem(airport->movements, &movement);                         //funcion de listADT.h
 }

MovementADT getMovement(AirportADT airport, OACI oaci){
	return getElem(airport->movements, oaci);                       //funcion de listADT.h
}