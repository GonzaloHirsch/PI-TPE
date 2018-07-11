///     ---------- INCLUDES ----------

#include "../Types.h"

///     ---------- IFNDEF ----------

#ifndef _LISTADT_H

#define _LISTADT_H

///     ---------- TYPEDEFS ----------

typedef struct ListCDT * ListADT;

///     ---------- FUNCTIONS ----------

/*
 * Generates and returns a new ListADT and sets the Generic getOaci function.
 */
ListADT newList(OACI (*getOaci)(void *), void (*freeElem) (void *));

/*
 * Adds element to the ListADT, arranged in Alphabetic Order based on its OACI.
 * Returns false if the element wasn't added because another element with same OACI exists.
 * Returns 2 if there wasn't memory available to allocate.
 */
int addElem(ListADT list, void * elem);

/*
 * Returns an element of the list based on its OACI.
 * Returns null if no element was found.
 */
void * getElem(ListADT list, OACI oaci);

/*
 * Free memory
 */
void freeListADT(ListADT list);

///     ---------- ITERATOR FUNCTIONS ----------

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

///     ---------- ----------

#endif