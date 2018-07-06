#ifndef _AirportTypes_h
#define _AirportTypes_h

// Boolean support
typedef int bool;
#define true 1
#define false 0

/*
 * Having all airport's types centralized allows us to no have to remember each
 * variable properties and eases and change we need in the future.
 */

// Local code of an airport (3 Chars from 'A' to 'Z')
typedef char tLocal[4];
typedef char * Local;

// OACI code of an airport (4 Chars from 'A' to 'Z')
typedef char tOACI[5];
typedef char * OACI;

// International code of an airport (Empty or 3 Chars from 'A' to 'Z')
typedef char tIATA[4];
typedef char * IATA;
                                       
// Name of an airport (Can contain ASCII extensions)
typedef char * Denomination;

// Traffic type of an airport
typedef enum { INTERNATIONAL, NATIONAL } TTraffic;

// Error types the program could encounter
typedef error errorTypes[7];
typedef char * error;


errorTypes allErrors = {
        {"No hay errores."},
                        {"Se recibieron demasiados argumentos, se espera 1 solo argumento."},
                        {"Se recibieron pocos argumentos, se espera 1 solo argumento."},
                        {"El argumento dado no es un año."},
                        {"El año tiene que estar entre 2014 y 2018"},
                        {"Error al tratar de abrir el archivo de vuelos."},
                        {"Error al tratar de abrir el archivo de movimientos."}



#endif
