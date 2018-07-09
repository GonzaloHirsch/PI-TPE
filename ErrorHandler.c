#include "ErrorHandler.h"
#include <stdio.h>
#include <stdlib.h>

void
verifyErrorType (TErrors errorType){

    switch (errorType){

        case NO_ERROR   :   printf("Se ejecutó de forma exitosa el programa!"); break;

        case MANY_ARGS  :   fprintf(stderr, "ERROR: Se recibieron demasiados argumentos, se espera 1 solo argumento.\n"); break;

        case FEW_ARGS   :   fprintf(stderr, "ERROR: Se recibieron pocos argumentos, se espera 1 solo argumento.\n");  break;

        case ARG_NOT_YEAR   :   fprintf(stderr, "ERROR: El argumento dado no es un año.\n");  break;

        case ARG_OUTOF_RANGE    :   fprintf(stderr, "ERROR: El año tiene que estar entre 2014 y 2018.\n"); break;

        case CANT_OPEN_MOV  :   fprintf(stderr, "ERROR: Al tratar de abrir el archivo de vuelos.\n");  break;

        case CANT_OPEN_AIRP :   fprintf(stderr, "ERROR: Al tratar de abrir el archivo de aeropuertos.\n");   break;

        case CANT_CREATE_FILE    :   fprintf(stderr, "ERROR: Al tratar de crear un archivo en un Query..\n");   break;

    }
}

void printWarning(TWarnings warning) {
    switch (warning){

        case MULTIPLE_OACI_ELEM :   printf("WARNING: Se intento agregar un elemento con un OACI ya existente.\n"); break;
    }

}
