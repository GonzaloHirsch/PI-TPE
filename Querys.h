#ifndef QUERYS_H

#define QUERYS_H

///     ---------- FUNCTION PROTOTYPES ----------

/*
 *  Query function 1, given the file and an airport, it prints all the info
 *  Parameters:
 *      FILE * file --> Output file
 *      AirportADT airport --> Airport to print the info required
 */
void Query1(FILE * file, AirportADT airport);

/*
 *  Query function 2, given the file and an airport, it prints all the info
 *  Parameters:
 *      FILE * file --> Output file
 *      AirportADT airport --> Airport to print the info required
 */
void Query2(FILE * file, AirportADT airport);

/*
 *  Query function 3, given the file and the array, it prints all the info
 *  Parameters:
 *  FILE * file --> Output file
 *      int * movPerDay --> Array containing the amount of movements per day, starting at Sunday and ending at Saturday
 */
void Query3(FILE * file, int * movPerDay);

/*
 *  Query function 4, given the file and an airport, it prints all the info
 *  Parameters:
 *      FILE * file --> Output file
 *      AirportADT airport --> Airport to print the info required
 */
void Query4(FILE * file, AirportADT airport);

/*
 * It processes the airport list, generating queries.
 * Parameters:
 *      AirportList airportList --> List containing all the airports.
 *      int * movPerDay --> Array containing the amount of movements per day, starting at Sunday and ending at Saturday.
 * Return Values:
 *      NO_ERROR --> If no errors occurred
 *      CANT_CREATE_FILE --> If there was an error when creating the new file
 */
TErrors QueryProcessing(AirportList airportList, int * movPerDay);

///     ---------- ----------

#endif

