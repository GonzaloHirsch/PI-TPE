#ifndef _ErrorHandler_h

#define _ErrorHandler_h

// Error types the program could encounter
typedef enum { NO_ERROR = 0, MANY_ARGS, FEW_ARGS, ARG_NOT_YEAR, ARG_OUTOF_RANGE, CANT_OPEN_MOV, CANT_OPEN_AIRP } TErrors;

//  Receives the error number and prints an error message according to the error and aborts the program with the corresponding error code.
void verifyErrorType (TErrors errorType);

#endif
