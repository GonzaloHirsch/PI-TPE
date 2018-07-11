#include "../Types.h"
#include "MovementADT.h"
#include "ListADT.h"

#ifndef _AirportADT_h

#define _AirportADT_h

/*
 * AirportADT is defined for each national airport, containing each of its properties
 */

typedef struct  AirportCDT * AirportADT;

typedef ListADT AirportList;

///     ---------- FUNCTION PROTOTYPES ----------

/*
 * Generates and returns new AirportADT, setting its OACI
 */
AirportADT newAirport(OACI oaci, IATA iata, Local local, Denomination denomination);

/*
 * Returns the amount of unknown departures of the airport passed through the parameters.
 */
int getAirportUnknownDepartures(AirportADT airport);

/*
 * Returns the amount of unknown arrivals of the airport passed through the parameters.
 */
int getAirportUnknownArrivals(AirportADT airport);

/*
 * Returns the local code of the airport passed through the parameters.
 */
Local getAirportLocal(AirportADT airport);

/*
 * Returns the OACI of the airport passed through the parameters.
 */
OACI getAirportOACI(AirportADT airport);

/*
 * Returns the IATA code of the airport passed through the parameters.
 */
IATA getAirportIATA(AirportADT airport);

/*
 * Returns the denomination of the airport passed through the parameters.
 */
Denomination getAirportDenomination(AirportADT airport);

/*
 * Returns a list containing all the movements of the airport passed through the parameters.
 */
MovementList getMovementList(AirportADT airport);

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
 * Adds a MovementADT to the Airport's list of movements
 * Return values:
 *      false - If there is no space to allocate memory.
 *      true - If there is space.
 */
bool addMovement(AirportADT airport, OACI oaci, bool isOaciKnown, bool isNational, bool isDeparture);

/*
 * Adds an airport to the airport list, if there is no airport with the given oaci code
 * Return values:
 *      false - If there is no space to allocate memory.
 *      true - If there is space.
 */
bool addAirport (AirportList airportList, OACI oaci, Local local, IATA iata, Denomination denomination);

/*
 * Free memory
 */
void freeAirportADT(AirportADT airport);

///     ---------- LIST FUNCTIONS ----------

/*
 * Creates a new ListADT, specific for AirportADTs.
 * Returns NULL if the is no memory.
 */
AirportList newAirportList();

/*
 * Returns an element with the specific OACI code from an AirportList.
 * Returns NULL if no element was found.
 */
AirportADT getAirportElem(AirportList list, OACI oaci);

///     ---------- ----------

#endif
