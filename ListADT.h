#include "AirportTypes.h"

#ifndef _ListADT_h
#define _ListADT_h

typedef struct ListCDT * ListADT;

/*
 * Generates and returns a new ListADT and sets the Generic getOaci function.
 */
ListADT newList(OACI (* getOaci)(void *));

/*
 * Adds element to the ListADT, arranged in Alphabetic Order based on its OACI.
 */
void addElem(ListADT list, void * elem);

/*
 * Returns an element of the list based on its OACI.
 * Returns null if no element was found.
 */
void * getElem(OACI oaci);

#endif
