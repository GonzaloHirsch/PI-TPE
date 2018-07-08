#include "ADT/AirportADT.h"
#include <stdio.h>
#include "ErrorHandler.h"

TErrors
Query3(int * movPerDay){

    //  Creates a new file for writing
    FILE * newFile = fopen("semanal.csv", "w");

    //  If the pointer is NULL, it means it couldn't create it
    if (newFile == NULL)
        return CANT_CREATE_FILE_Q3;

    char * days[7] = {"Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado", "Domingo"};

    /*
     * Prints each day with the corresponding amount of movements
     * We use ((i + 1) % 7) as an index because the first day in movPerDay is Sunday,
     * so we have to start in 1 and the last one to be 0.
     */
    for (int i = 0; i < 7; i++)
        fprintf(newFile, "%s;%d\n", days[i], movPerDay[(i + 1) % 7]);

    fclose(newFile);
    return NO_ERROR;
}