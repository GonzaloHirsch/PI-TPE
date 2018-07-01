#ifndef _AirportTypes_h
#define _AirportTypes_h

// Local code of an airport (3 Chars from 'A' to 'Z')
typedef char Local[4];

// OACI code of an airport (4 Chars from 'A' to 'Z')
typedef char OACI[5];

// International code of an airport (Empty or 3 Chars from 'A' to 'Z')
typedef char IATA[4];
                                       
// Name of an airport (Can contain ASCII extensions)
typedef int * Denomination;
>>>>>>> e618f9d6f2ead183fbddeb2dbb8254a8a99a8eac

// Traffic type of an airport
typedef enum { INTERNATIONAL, NATIONAL } TTraffic;

#endif
