#include "Types.h"

#ifndef _ListADT_h
#define _ListADT_h

typedef struct ListCDT * ListADT;

/*
 * Generates and returns a new ListADT and sets the Generic getOaci function.
 */
ListADT newList(OACI (*getOaci)(void *), void (*freeElem) (void *));

/*
 * Adds element to the ListADT, arranged in Alphabetic Order based on its OACI.
 */
void addElem(ListADT list, void * elem);

/*
 * Returns an element of the list based on its OACI.
 * Returns null if no element was found.
 */
void * getElem(ListADT list, OACI oaci);

/*
 * Sets iterator to start of the list.
 */
void toStart(ListADT list);

/*
 * Returns and sets iterator to next element.
 */
void * getNext(ListADT list);

/*
 * Returns true if the next element of the iterator is not NULL.
 */
bool hasNext(ListADT list);

/*
 * Free memory
 */
void freeListADT(ListADT list);

#endif