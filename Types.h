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

// Traffic type of an airport.
typedef enum { INTERNATIONAL, NATIONAL } TTraffic;

//  All the token indexes we are interested in, in the movements file.
typedef enum { M_DATE = 0, M_TYPE = 3, M_CLASS = 4, M_ORIGIN = 5, M_DESTIN = 6 } TokenMovIndex;

//  All the token indexes we are interested in, in the airports file.
typedef enum {A_LOCAL = 0, A_OACI = 1, A_IATA = 2, A_DENOM = 4, A_TYPE = 18 } TokenAirpIndex;

#endif
