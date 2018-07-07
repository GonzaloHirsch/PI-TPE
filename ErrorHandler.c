#include "ErrorHandler.h"
#include <stdio.h>
#include <stdlib.h>

void
verifyErrorType (TErrors errorType){

    switch (errorType){

        case NO_ERROR   :   break;

        case MANY_ARGS  :   printf("ERROR: Se recibieron demasiados argumentos, se espera 1 solo argumento.\n"); break;

        case FEW_ARGS   :   printf("ERROR: Se recibieron pocos argumentos, se espera 1 solo argumento.\n");  break;

        case ARG_NOT_YEAR   :   printf("ERROR: El argumento dado no es un año.\n");  break;

        case ARG_OUTOF_RANGE    :   printf("ERROR: El año tiene que estar entre 2014 y 2018.\n"); break;

        case CANT_OPEN_MOV  :   printf("ERROR: Al tratar de abrir el archivo de movimientos.\n");  break;

        case CANT_OPEN_AIRP :   printf("ERROR: Al tratar de abrir el archivo de vuelos.\n");   break;

        case MULTIPLE_ELEMS_OACI    :   printf("ERROR: Multiples elementos con el mismo codigo OACI en una lista.\n");  break;

    }

    if(errorType != NO_ERROR)
        exit(errorType);
}