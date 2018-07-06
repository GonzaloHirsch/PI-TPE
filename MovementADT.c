#include <endian.h>
#include "MovementADT.h"

typedef struct MovementCDT{
  OACI oaci;
  bool isLocal;
  int arrivals;
  int departures;
} MovementCDT;

MovementADT newMovement(OACI oaci, bool isLocal){
	MovementADT retVal = malloc(sizeof(MovementCDT));
	strcpy(retVal->oaci,oaci);
	retVal->isLocal = isLocal;
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

///////////////////////  LIST FUNCTIONS BELOW

MovementList newMovementList() {
    return newList( (OACI (*) (void *)) getMovementOACI);
}

void addMovementElem(MovementList list, MovementADT elem) {
    addElem(list,elem);
}

MovementADT getMovementElem(MovementList list, OACI oaci) {
    return getElem(list,oaci);
}


