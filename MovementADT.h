#include "AirportTypes.h"

#ifndef _MovementADT_h
#define _MovementADT_h

typedef struct MovementCDT * MovementADT;

/*
 * Generates and returns new MovementADT, setting its OACI
 */
MovementADT newMovement(OACI oaci);

/*
 * Returns the OACI of the MovementADT passed through the parameters.
 */
OACI getMovementOACI(MovementADT movement);

#endif
