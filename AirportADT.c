#include "AirportADT.h"
#include "ListADT.h"

typedef struct {
    char local[3];
    char oaci[4];
    char iata[3];
    char denomination[70];
    ListADT movements;
 } Airport;


struct AirportCDT {

};
