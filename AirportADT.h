#include "AirportTypes.h"

#ifndef _AirportADT_h
#define _AirportADT_h

typedef  AirportCDT * AirportADT;

AirportADT newAirport(OACI oaci);

OACI getAirportOACI(AirportADT airport);

#endif
