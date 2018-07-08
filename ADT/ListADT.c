#include <stdlib.h>
#include <string.h>
#include "ListADT.h"
#include "ErrorHandler.h"

 struct node{
    void * elem;
    struct node * tail;
 };

typedef struct node * TNode;

 struct ListCDT {
        TNode head;
        TNode iterator;
        OACI (* getOaci) (void *);
        void (* freeElem) (void *);
 };


ListADT newList(OACI (*getOaci)(void *), void (* freeElem)(void *)) {
    ListADT list = calloc(1, sizeof(*list));
    list -> getOaci = getOaci;
    list -> freeElem = freeElem;
    return list;
}


TNode addElemRec(TNode node, void * elem, OACI (* getOaci) (void *)){
    int c;
    if(node == NULL || (c = strcmp(getOaci(elem), getOaci(node -> elem))) < 0){
        TNode newNode = malloc(sizeof(*newNode));
        newNode -> elem = elem;
        newNode -> tail = node;
        return newNode;
    }
    else if(c > 0){
        node -> tail = addElemRec(node -> tail, elem, getOaci);
        return node;
    } else {
        verifyErrorType(MULTIPLE_ELEMS_OACI);
    }
}

void addElem(ListADT list, void * elem) {
    list -> head = addElemRec(list -> head, elem, list -> getOaci);
}


void * getElem(ListADT list, OACI oaci) {
    TNode node = list -> head;
    while(node != NULL){
        if(strcmp(list -> getOaci(node ->elem), oaci) == 0)
            return node -> elem;
        node = node -> tail;
    }
    return NULL;
}

void freeListADT(ListADT list){
    TNode node = list -> head;
    while (node != NULL){
        list->freeElem(node -> elem);
        TNode aux = node -> tail;
        free(node);
        node = aux;
    }
    free(list);
}

void toStart(ListADT list) {
    list -> iterator = list -> head;
}

void *getNext(ListADT list) {
    TNode aux = list -> iterator;
    list -> iterator = list -> iterator -> tail;
    return aux -> elem;
}

bool hasNext(ListADT list) {
    return list -> iterator != NULL;
}

/*
 * AirportList list = newAirportList(...) ... Agrego Datos ...
 * toStart(list)
 * while(hasNext(list))
 *      AirportADT airport = (AirportADT) getNext(list)
 *      printf(getAirportOACI(airport))
 */