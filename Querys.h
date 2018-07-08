
#ifndef QUERYS_H

#define QUERYS_H

/*
 *  Query function 3, it creates a new file and then it prints all the info
 *  Parameters:
 *      int * movPerDay --> Array containing the amount of movements per day, starting at Sunday and ending at Saturday
 *  Return Values:
 *      NO_ERROR --> If no errors occurred
 *      CANT_CREATE_FILE --> If there was an error when creating the new file
 */
TErrors Query3(int * movPerDay);

/*
 *  Query function 1 and 2, it creates 2 new files and then it prints all the info.
 *  Parameters:
 *      AirportList airportList --> List containing all the airports.
 *  Return Values:
 *      NO_ERROR --> If no errors occurred
 *      CANT_CREATE_FILE --> If there was an error when creating the new file
 */
TErrors Query1and2(AirportList airportList);

/*
 *  Query function 4, it creates a new file and then it prints all the info.
 *  Parameters:
 *      AirportList airportList --> List containing all the airports.
 *  Return Values:
 *      NO_ERROR --> If no errors occurred
 *      CANT_CREATE_FILE --> If there was an error when creating the new file
 */
TErrors Query4(AirportList airportList);

#endif

