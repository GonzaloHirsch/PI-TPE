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
 * Returns the local code of the airport passed through the parameters.
 */
Local getAirportLocal(AirportADT airport);

/*
 * Returns the denomination of the airport passed through the parameters.
 */
Denomination getAirportDenomination(AirportADT airport);

/*
 * Returns the amount of total movements of the airport passed through the parameters.
 */
int getAirportTotalMovements(AirportADT airport);

/*
 * Returns the amount of international arrivals of the airport passed through the parameters.
 */
int getAirportInternationalArrivals(AirportADT airport);

/*
 * Returns the amount of international departures of the airport passed through the parameters.
 */
int getAirportInternationalDepartures(AirportADT airport);

/*
 * Returns the IATA code of the airport passed through the parameters.
 */
IATA getAirportIATA(AirportADT airport);

/*
 * Adds a MovementADT to the Airport's list of movements
 */
void addMovement(AirportADT airport, MovementADT movement);

/*
 * Adds a certain amount of unknown departures to the airport passed.
 */
void addUnknownDeparture (AirportADT airport, int amount);

/*
 * Adds a certain amount of unknown arrivals to the airport passed.
 */
void addUnknownArrival (AirportADT airport, int amount);

/*
 * Adds a certain amount of international arrivals to the airport passed.
 */
void addInternationalArrival (AirportADT airport, int amount);

/*
 * Adds a certain amount of international departures to the airport passed.
 */
void addInternationalDeparture (AirportADT airport, int amount);

/*
 * Adds a certain amount of movements to the airport passed.
 */
void addTotalMovement (AirportADT airport, int amount);

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

/*
 * Free memory
 */
void freeAirportADT(AirportADT airport);

#endif
