///     ---------- IFNDEF ----------

#ifndef _ERRORHANDLER_H

#define _ERRORHANDLER_H

///     ---------- TYPEDEFS ----------

// Error types the program could encounter
typedef enum { NO_ERROR = 0, MANY_ARGS, FEW_ARGS, ARG_NOT_YEAR, ARG_OUTOF_RANGE, CANT_OPEN_MOV, CANT_OPEN_AIRP, CANT_CREATE_FILE, NO_MEM_TO_ALLOC } TErrors;

typedef enum { MULTIPLE_OACI_ELEM } TWarnings;

///     ---------- FUNCTION PROTOTYPES ----------

/*
 *  Receives the error number and prints an error message (to stderr) according to the error.
 *  In case there was no error it prints a message also.
 *  Parameters:
 *      TErrors errorType --> Error number
 */
void verifyErrorType (TErrors errorType);

/*
 *  Receives the warning number and prints a warning message according to the warning.
 *  Parameters:
 *      TWarnings warning --> Warning number
 */
void printWarning(TWarnings warning);

///     ---------- ----------

#endif
