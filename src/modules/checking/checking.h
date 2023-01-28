#ifndef CHECK_H
#define CHECK_H

#include <stdbool.h>
#include "../instructionList/instructionList.h"

typedef enum {
    INFORMATION,
    WARNING,
    ERROR
} ErrorSeverity;

typedef enum {
    BRACKET_AMOUNT_DOES_NOT_MATCH
} ErrorType;

char * errorMessages[] = {
    "Warning: The amount of left brackets and right brackets don't match."
};

typedef struct error {
    char * errorMessage;
    ErrorSeverity severity;
    ErrorType type;
    struct error * nextError;
} Error;

typedef struct errorList {
    Error * begin;
    Error * end;
    size_t errorListLength;
} ErrorList;

ErrorList * checkInstructions(const InstructionList * instructionList, bool printWarnings);

ErrorList * newErrorList(void);
Error * addError(ErrorList * errorList, ErrorSeverity severity, ErrorType type);
void freeErrorList(ErrorList * errorList);

#endif