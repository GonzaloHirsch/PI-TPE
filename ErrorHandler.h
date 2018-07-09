#ifndef _ErrorHandler_h

#define _ErrorHandler_h

// Error types the program could encounter
typedef enum { NO_ERROR = 0, MANY_ARGS, FEW_ARGS, ARG_NOT_YEAR, ARG_OUTOF_RANGE, CANT_OPEN_MOV, CANT_OPEN_AIRP, CANT_CREATE_FILE } TErrors;

typedef enum { MULTIPLE_OACI_ELEM } TWarnings;

//  Receives the error number and prints an error message (to stderr) according to the error.
void verifyErrorType (TErrors errorType);

void printWarning(TWarnings warning);

#endif
