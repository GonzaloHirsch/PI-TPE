#include <endian.h>
#include "MovementADT.h"

typedef struct MovementCDT{
  OACI oaci;
  bool isLocal;
  int arrivals;
  int departures;
} MovementCDT;

MovementList newMovementList() {
    return newList( (OACI (*) (void *)) getMovementOACI);
}

void addMovementElem(MovementList list, MovementADT elem) {
    addElem(list,elem);
}

MovementADT getMovementElem(MovementList list, OACI oaci) {
    return getElem(list,oaci);
}


