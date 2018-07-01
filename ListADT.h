#include "AirportTypes.h"

#ifndef _ListADT_h

#define _ListADT_h

typedef struct ListCDT * ListADT;

ListADT newList(OACI (* getOaci)(void *));

int addElem(ListADT list, void * elem);



#endif
