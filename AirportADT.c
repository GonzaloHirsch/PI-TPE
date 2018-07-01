#include "AirportADT.h"
#include "ListADT.h"
#include "AiportTypes.h"

typedef struct {
    Local local;
    OACI oaci;
    IATA iata;
    Denomination denomination;
    TTraffic traffic;
    ListADT movements;
 } Airport;


struct AirportCDT {
    Airport airport;
};
