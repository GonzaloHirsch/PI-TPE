#include "MovementADT.h"

struct Movement {
  char oaci[4];
  int isLocal;
  int arrivals;
  int departures;
};

struct MovementCDT {
  Movement movement;
};
