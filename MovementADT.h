#include "AirportTypes.h"

#ifndef _MovementADT_h
#define _MovementADT_h

typedef MovementCDT * MovementADT;

MovementADT newMovement(OACI oaci);

OACI getMovementOACI(MovementADT movement);

#endif
