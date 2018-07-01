#include "MovementADT.h"

typedef struct{
  char oaci[4];
  int isLocal;
  int arrivals;
  int departures;
} Movement;

struct MovementCDT {
    Movement movement;
};
