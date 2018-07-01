#include "AirportTypes.h"
#include "MovementADT.h"

#ifndef _AirportADT_h
#define _AirportADT_h


/*Local local;
    OACI oaci;
    IATA iata;
    Denomination denomination;
    TTraffic traffic;
    ListADT movements;
    */

typedef struct  AirportCDT * AirportADT;

/*
 * Generates and returns new AirportADT, setting its OACI
 */
AirportADT newAirport(OACI oaci);


/*
 * Sets the AirportADT's IATA
 */
void setIATA(AirportADT airport, IATA iata);

/*
 * Sets the AirportADT's denomination
 */
void setDenomination(AirportADT airport, Denomination denomination);

/*
 * Sets the AirportADT's traffic
 */
void setTraffic(AirportADT airport, TTraffic traffic);

/*
 * Returns the OACI of the AirportADT passed through the parameters.
 */
OACI getAirportOACI(AirportADT airport);

/*
 * Adds a MovementADT to the AirportADT specified
 */
void addMovement(AirportADT airport, MovementADT movement);

/*
 * Returns the MovementADT which corresponds to the OACI specified in the Airport's movement list
 * Returns null if the OACI doesn't correspond to any movement
 */
MovementADT getMovement(AirportADT airport, OACI oaci);

#endif
