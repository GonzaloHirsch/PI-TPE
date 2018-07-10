#include <string.h>
#include <stdlib.h>
#include "MovementADT.h"

typedef struct MovementCDT{
  tOACI oaci;
  int arrivals;
  int departures;
} MovementCDT;

MovementADT newMovement(OACI oaci){
	MovementADT retVal = malloc(sizeof(MovementCDT));	//TODO verificar que no haya espacio aca

    //  If there is no space it returns NULL
    if (retVal == NULL)
        return retVal;

	strcpy(retVal->oaci,oaci);
	retVal->arrivals = retVal->departures = 0;
	return retVal;
}

OACI getMovementOACI(MovementADT movement){
	return movement->oaci;
}

void addArrival(MovementADT movement, int amount){
	movement->arrivals += amount;
}

void addDeparture(MovementADT movement, int amount){
	movement->departures += amount;
}

int getArrivals(MovementADT movement){
	return movement->arrivals;
}

int getDepartures(MovementADT movement){
	return movement->departures;
}

void freeMovementADT(MovementADT movement){
    free(movement);
}

/// --- LIST FUNCTIONS ---

MovementList newMovementList() {
    return newList( (OACI (*) (void *)) getMovementOACI, (void (*) (void *)) freeMovementADT);
}

bool addMovementElem(MovementList list, MovementADT elem) {
    return addElem(list, elem);
}

MovementADT getMovementElem(MovementList list, OACI oaci) {
    return getElem(list,oaci);
}

/// --- ----


