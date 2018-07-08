
#ifndef QUERYS_H

#define QUERYS_H

/*
 *  Query function 3, it creates a new file and then it prints all the info
 *  Parameters:
 *      int * movPerDay --> Array containing the amount of movements per day, starting at Sunday and ending at Saturday
 *  Return Values:
 *      NO_ERROR --> If no errors occurred
 *      CANT_CREATE_FILE_Q3 --> If there was an error when creating the new file
 */
TErrors Query3(int * movPerDay);

#endif

