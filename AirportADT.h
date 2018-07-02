#include "Types.h"
#include "MovementADT.h"

#ifndef _AirportADT_h
#define _AirportADT_h

typedef struct  AirportCDT * AirportADT;

/*
 * Generates and returns new AirportADT, setting its OACI
 */
AirportADT newAirport(OACI oaci);


/*
 * Sets the airport's IATA
 */
void setIATA(AirportADT airport, IATA iata);

/*
 * Allocates memory in heap and copies the passed denomination. Then sets the airport's to denomination to the allocated memory.
 */
void setDenomination(AirportADT airport, char denomination[]);

/*
 * Sets the airport's traffic
 */
void setTraffic(AirportADT airport, TTraffic traffic);

/*
 * Returns the OACI of the airport passed through the parameters.
 */
OACI getAirportOACI(AirportADT airport);

/*
 * Adds a MovementADT to the Airport's list of movements
 */
void addMovement(AirportADT airport, MovementADT movement);

/*
 * Returns the MovementADT which corresponds to the OACI specified in the airport's movements list
 * Returns null if the OACI doesn't correspond to any movement
 */
MovementADT getMovement(AirportADT airport, OACI oaci);

/*
 * Increments the total amount of movements by the specified amount
 */
void incrementTotalMovements(AirportADT airport, int amount);

#endif
