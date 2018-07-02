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
    int totalMovements;
    ListADT movements;
 } AirportCDT;

 AirportADT newAirport(OACI oaci){
 	AirportADT retVal = calloc(1, sizeof(AirportCDT));
 	strcpy(retVal->oaci, oaci);
 	return retVal;
 }

 void setIATA(AirportADT airport, IATA iata){
 	strcpy(airport->iata, iata);
 }


 void setDenomination(AirportADT airport, Denomination denomination){
 	airport -> denomination = realloc(airport -> denomination, strlen(denomination) + 1);
 	strcpy(airport -> denomination, denomination);
 }


 void setTraffic(AirportADT airport, TTraffic traffic){
 	airport->traffic = traffic;
 }

 OACI getAirportOACI(AirportADT airport){
 	return airport->oaci;
 }

 void addMovement(AirportADT airport, MovementADT movement){
 	
 }
