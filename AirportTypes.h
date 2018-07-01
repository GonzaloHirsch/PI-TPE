#ifndef _AirportTypes_h
#define _AirportTypes_h

// Local code of an airport
typedef char Local[3];

// OACI code of an airport
typedef char OACI[4];

// International code of an airport
typedef char IATA[3];

// Name of an airport
typedef int Denomination[70];

// Traffic type of an airport
typedef enum { INTERNATIONAL, NATIONAL } TTrafic;

// Movement type of a flight
typedef enum { ARRIVAL, DEPARTURE } TMovement;


#endif
