#include <stdlib.h>

#ifndef _ProcessData_h
#define _ProcessData_h

//	Constants Definitions
//  Movement Constants
#define MAX_TEXT_MOVEMENT 150
//  --------------  Named Fields
#define ARRIVAL "Aterrizaje"
#define M_DEPARTURE "Despegue"
#define C_INTERNATIONAL "Internacional"
#define M_LOCAL "Cabotaje"

//  Airport Constants
#define MAX_TEXT_AIRPORT 300
//  --------------  Named Fields
#define A_NATIONAL "Nacional"

//  All the token indexes we are interested in, in the movements file.
typedef enum { M_DATE = 0, M_TYPE = 3, M_CLASS = 4, M_ORIGIN = 5, M_DESTIN = 6 } TokenMovIndex;

//  All the token indexes we are interested in, in the airports file.
typedef enum {A_LOCAL = 0, A_OACI = 1, A_IATA = 2, A_DENOM = 4, A_TYPE = 18 } TokenAirpIndex;

/*
 * Alternative for strtok. separateToken replaces delimiter with NULL and stores each token in an array.
 * Parameters:
 * char * str --> Source string. This string will be modified, can't be const.
 * char del --> Character delimiter.
 * char ** strArr --> Array of strings which will store all the strings separated by the delimiter.
 * size_t dim --> Max dimension of strArr.
 * Returns size_t --> New size of strArr.
 */
size_t separateToken(char *str, char del, char ** strArr, size_t dim);

/*
 *  Verifies whether or not the OACI code from the airport is unknown.
 *  Unknown OACI codes have this layout (x is a digit):
 *      SAxx
 *      AR-xxxx
 *  Parameters:
 *      const char * airportOACI --> Constant string containing the airport OACI.
 *  Return values:
 *      0 - if OACI is KNOWN.
 *      1 - if OACI is UNKNOWN.
 */
int isUnknownOACI(const char * airportOACI);

/*
 * 	Given a date, it calculates the day of the week.
 * 	Parameters:
 * 	    const char * date --> Constant string containing the date in format dd/mm/yyyy.
 * 	    int * dayCode --> Array containing the code (an integer) for each day in the week.
 * 	    int * monthCode --> Array containing the code (an integer) for each month.
 * 	    int * yearCode --> Array containing the code (an integer) for each year we are interested in.
 * 	Return value:
 * 	    Integer representing the day of the week for the array movPerDay[]
 */
int
dateToDayOfWeek (const char * date, int * dayCode, int * monthCode, int * yearCode);

/*
 * 	Extracts the day, month and year from a given date.
 * 	Parameters:
 * 	    const char * date --> Constant string containing the date in format dd/mm/yyyy.
 * 	    int * day --> Pointer to the day extracted.
 * 	    int * month --> Pointer to the month extracted.
 * 	    int * year --> Pointer to the year extracted.
 */
void getDate (const char * date, int * day, int * month, int * year);

/*
 * 	Verifies whether or not the year it receives is the year we want.
 * 	Parameters:
 * 	    const char * date --> Constant string containing the date in format dd/mm/yyyy.
 * 	    int yearGiven --> The year the user gave the program.
 * 	Return values:
 * 	    0 - If its NOT the year we want.
 * 	    1 - If it IS the year we want.
 */
int verifyYear (const char * date, int yearGiven);

/*
 *  Verifies whether or not the string passed is only digits.
 *  Parameters:
 *      const char * str --> Constant string to be verified.
 *  Return values:
 *      0 - If the string contains not only numbers.
 *      1 - If the string contains only numbers.
 */
int verifyString (const char * str);

#endif
