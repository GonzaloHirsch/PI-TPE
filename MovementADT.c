#include "MovementADT.h"

typedef struct{
  OACI oaci;
  int isLocal;
  int arrivals;
  int departures;
} Movement;

struct MovementCDT {
    Movement movement;
};
