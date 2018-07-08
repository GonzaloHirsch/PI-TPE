#include <stdlib.h>
#include <string.h>
#include "ListADT.h"

 struct node{
    void * elem;
    struct node * tail;
 };

typedef struct node * TNode;

 struct ListCDT {
        TNode head;
        TNode iterator;
        OACI (* getOaci) (void *);
        void (*freeNode) (void *);
 };


ListADT newList(OACI (*getOaci)(void *), void (*freeNode)(void *)){
    ListADT list = calloc(1, sizeof(*list));
    list -> getOaci = getOaci;
    list -> freeNode = freeNode;
    return list;
}


TNode addElemRec(TNode node, void * elem, OACI (* getOaci) (void *)){
    int c;
    if(node == NULL || (c = strcmp(getOaci(elem), getOaci(node -> elem))) > 0){
        TNode newNode = malloc(sizeof(*newNode));
        newNode -> elem = elem;
        newNode -> tail = node;
        return newNode;
    }
    else if(c < 0){
        node -> tail = addElemRec(node -> tail, elem, getOaci);
        return node;
    } else{
        // TODO: PRINT ERROR. MULTIPLE ELEMENTS WITH SAME OACI
    }
}

void addElem(ListADT list, void * elem) {
    list -> head = addElemRec(list -> head, elem, list -> getOaci);
}


void *getElem(ListADT list, OACI oaci) {
    TNode node = list -> head;
    while(node != NULL){
        if(strcmp(list -> getOaci(node ->elem), oaci) == 0)
            return node -> elem;
        node = node -> tail;
    }
    return NULL;
}

void toStart(ListADT list){
	list->iterator = list->head;
}

bool hasNext(ListADT list){
	return (list->iterator == NULL);
}

void * getNext(ListADT list){
	if (! hasNext(list))
		exit(1);                   //////Error Handler?
	void * retVal = iterator->elem;
	iterator = iterator->tail;
	return retVal;
}

void freeList(listADT list){
	toStart(list);
	TNode aux;
	while(list->iterator){
		list->freeNode(list->iterator->elem);
		aux = list->iterator;
		list->iterator = list->iterator->tail;
		free(aux);
	}
}
