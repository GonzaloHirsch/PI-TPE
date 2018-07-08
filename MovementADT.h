#include "Types.h"
#include "ListADT.h"

#ifndef _MovementADT_h
#define _MovementADT_h

/*
 * MovementADT specifies the amount of movements arriving from or departing to the airport of specified OACI
 */
typedef struct MovementCDT * MovementADT;

typedef ListADT MovementList;

/*
 * Generates and returns new MovementADT, setting its OACI and if it's a local airport.
 */
MovementADT newMovement(OACI oaci, bool isLocal);

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
 * Frees the memory allocated for a MovementADT element
 */
void freeMovement(MovementADT movement);


///////////////////////  LIST FUNCTIONS //////////////////////////////

/*
 * Creates a new ListADT, specific for MovementADTs.
 */
MovementList newMovementList();

/*
 * Adds an element to the MovementList, in order of OACI.
 */
void addMovementElem(MovementList list, MovementADT elem);

/*
 * Returns an element with the specific OACI code from a MovementList.
 * Returns NULL if no element was found.
 */
MovementADT getMovementElem(MovementList list, OACI oaci);

/*
 * Frees the MovementList
*/
void freeMovementList(MovementList list);

#endif
