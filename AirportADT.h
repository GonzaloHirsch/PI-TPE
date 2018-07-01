#include "AirportTypes.h"
#include "MovementADT.h"

#ifndef _AirportADT_h
#define _AirportADT_h

typedef struct  AirportCDT * AirportADT;

/*
 * Generates and returns new AirportADT, setting its OACI
 */
AirportADT newAirport(OACI oaci);

/*
 * Returns the OACI of the AirportADT passed through the parameters.
 */
OACI getAirportOACI(AirportADT airport);

/*
 * Adds a MovementADT to the list of movements
 */
void addMovement(AirportADT airport, MovementADT movement);

#endif
