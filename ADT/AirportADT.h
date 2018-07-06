#include "Types.h"
#include "MovementADT.h"
#include "ListADT.h"

#ifndef _AirportADT_h
#define _AirportADT_h

typedef struct  AirportCDT * AirportADT;

typedef ListADT AirportList;

/*
 * Generates and returns new AirportADT, setting its OACI
 */
AirportADT newAirport(OACI oaci);

/*
 * Generates and returns new AirportADT from an array of tokens
 */
AirportADT newAirportFromTokens(char ** tokens);


/*
 * Sets the airport's Local Code
 */
void setLocalCode(AirportADT airport, Local local);

/*
 * Sets the airport's IATA
 */
void setIATA(AirportADT airport, IATA iata);

/*
 * Allocates memory in heap and copies the passed denomination. Then sets the airport's to denomination to the allocated memory.
 */
void setDenomination(AirportADT airport, char denomination[]);

/*
 * Sets the airport's traffic
 */
void setTraffic(AirportADT airport, TTraffic traffic);

/*
 * Returns the OACI of the airport passed through the parameters.
 */
OACI getAirportOACI(AirportADT airport);

/*
 * Adds a MovementADT to the Airport's list of movements
 */
void addMovement(AirportADT airport, MovementADT movement);

/*
 * Returns the MovementADT which corresponds to the OACI specified in the airport's movements list
 * Returns null if the OACI doesn't correspond to any movement
 */
MovementADT getMovement(AirportADT airport, OACI oaci);

/*
 * Creates a new ListADT, specific for AirportADTs.
 */
AirportList newAirportList();

/*
 * Adds an element to the AirportList, in order of OACI.
 */
void addAirportElem(AirportList list, AirportADT elem);

/*
 * Returns an element with the specific OACI code from an AirportList.
 * Returns NULL if no element was found.
 */
AirportADT getAirportElem(AirportList list, OACI oaci);

/* TODO FREE AIRPORT
 * Free memory
 */
void freeAiportADT(AirportADT airport);

#endif
