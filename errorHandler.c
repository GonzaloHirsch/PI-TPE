#include "errorHandler.h"
#include <stdio.h>

void
verifyErrorType (TErrors errorType){

    switch (errorType){

        case NO_ERROR  :   break;

        case MANY_ARGS  :   printf("Se recibieron demasiados argumentos, se espera 1 solo argumento."); break;

        case FEW_ARGS   :   printf("Se recibieron pocos argumentos, se espera 1 solo argumento.");  break;

        case ARG_NOT_YEAR   :   printf("El argumento dado no es un año.");  break;

        case ARG_OUTOF_RANGE    :   printf("El año tiene que estar entre 2014 y 2018"); break;

        case CANT_OPEN_MOV  :   printf("Error al tratar de abrir el archivo de movimientos.");  break;

        case CANT_OPEN_AIRP :   printf("Error al tratar de abrir el archivo de vuelos.");   break;

    }

    if (errorType != NO_ERROR)
        exit(errorType);
}