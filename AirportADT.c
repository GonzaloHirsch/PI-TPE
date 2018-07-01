#include "AirportADT.h"

typedef struct AirportCDT {
    Local local;
    OACI oaci;
    IATA iata;
    Denomination denomination;
    TTraffic traffic;
    ListADT movements;
 } AirportCDT;

 AirportADT newAirport(OACI oaci){
 	AirportADT retVal = malloc(sizeof(AirportCDT));
 	strcpy(retVal->oaci, oaci);
 	return retVal;
 }

 void setIATA(AirportADT airport, IATA iata){
 	strcpy(airport->iata, iata);
 }

 void setDenomination(AirportADT airport, Denomination denomination){
 	
 }

