#include <string.h>
#include <stdlib.h>
#include "MovementADT.h"

typedef struct MovementCDT{
  OACI oaci;
  bool isNational;
  int arrivals;
  int departures;
} MovementCDT;

MovementADT newMovement(OACI oaci, bool isNational){
	MovementADT retVal = malloc(sizeof(MovementCDT));
	strcpy(retVal->oaci,oaci);
	retVal->isNational = isNational;
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

bool isMovementLocal(MovementADT movement) {
    return movement -> isNational;
}

void freeMovementADT(MovementADT movement){
    free(movement);
}

/// --- LIST FUNCTIONS ---

MovementList newMovementList() {
    return newList( (OACI (*) (void *)) getMovementOACI, (void (*) (void *)) freeMovementADT);
}

void addMovementElem(MovementList list, MovementADT elem) {
    addElem(list,elem);
}

MovementADT getMovementElem(MovementList list, OACI oaci) {
    return getElem(list,oaci);
}

/// --- ----


