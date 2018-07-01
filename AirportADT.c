#include "AirportADT.h"

typedef struct AirportCDT {
    Local local;
    OACI oaci;
    IATA iata;
    Denomination denomination;
    TTraffic traffic;
    ListADT movements;
 } AirportCDT;