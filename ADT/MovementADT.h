#include "../Types.h"
#include "ListADT.h"

#ifndef _MOVEMENTADT_H

#define _MOVEMENTADT_H

/*
 * MovementADT specifies the amount of movements arriving from or departing to the airport of specified OACI
 */

typedef struct MovementCDT * MovementADT;

typedef ListADT MovementList;

///     ---------- FUNCTIONS ----------

/*
 * Generates and returns new MovementADT, setting its OACI and if it's a local airport.
 */
MovementADT newMovement(OACI oaci);

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

/*
 * Returns the MovementADT's total amount of arrivals
 */
int getArrivals(MovementADT movement);

/*
 * Returns the MovementADT's total amount of departures
 */
int getDepartures(MovementADT movement);

/*
 * Free memory
 */
void freeMovementADT(MovementADT movement);

///     ---------- LIST FUNCTIONS ----------

/*
 * Creates a new ListADT, specific for AirportADTs.
 * Returns NULL if the is no memory.
 */
MovementList newMovementList();

/*
 * Returns an element with the specific OACI code from an AirportList.
 * Returns NULL if no element was found.
 */
MovementADT getMovementElem(MovementList list, OACI oaci);

/*
 * Returns iterator and sets it to the next elem from the MovementList
 */
MovementADT getNextMovement(MovementList list);

///     ---------- ----------

#endif
