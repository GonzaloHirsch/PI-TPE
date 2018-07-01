#include "MovementADT.h"

typedef struct{
  OACI oaci;
  bool isLocal;
  int arrivals;
  int departures;
} Movement;

struct MovementCDT {
    Movement movement;
};
