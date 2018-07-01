#include "AirportTypes.h"

#ifndef _MovementADT_h
#define _MovementADT_h

/*
 * MovementADT specifies the amount of movements arriving from or departing to the airport of specified OACI
 */
typedef struct MovementCDT * MovementADT;

/*
 * Generates and returns new MovementADT, setting its OACI and if it's a local airport.
 */
MovementADT newMovement(OACI oaci, int isLocal);

/*
 * Returns the OACI of the MovementADT passed through the parameters.
 */
OACI getMovementOACI(MovementADT movement);

/*
 * Adds a certain amount of arrivals to the MovementADT
 */
void addArrival(MovementADT movement, int amount);

/*
 * Adds a certain amount of departures to the MovementADT
 */
void addDeparture(MovementADT movement, int amount);

#endif
