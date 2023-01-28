#include "checking.h"
#include <stdlib.h>
#include "../instructionList/instructionList.h"
#include "../instructions/instructions.h"

ErrorList * checkInstructions(const InstructionList *instructionList, bool printWarnings)
{
    ErrorList * errorList = (ErrorList*) malloc(sizeof(errorList));

    if(!errorList)
        return NULL;

    // Bracket amount matching - check 1
    size_t leftBracketAmount = 0;
    size_t rightBracketAmount = 0;

    for (InstructionNode *ptr = instructionList->begin; ptr != NULL; ptr = ptr->nextInstructionNode)
    {
        // Bracket amount matching - check 1
        switch (ptr->instruction.type)
        {
        case CONDITIONAL_START:
            ++leftBracketAmount;
            break;
        case CONDITIONAL_END:
            ++rightBracketAmount;
            break;
        default:
            break;
        }
    }

    if (leftBracketAmount != rightBracketAmount)
    {
        addError(errorList, WARNING, BRACKET_AMOUNT_DOES_NOT_MATCH);
    }

    return errorList;
}

ErrorList *newErrorList(void)
{
    ErrorList *errorList = (ErrorList *)malloc(sizeof(ErrorList));
    if (errorList)
    {
        errorList->begin = NULL;
        errorList->end = NULL;
        errorList->errorListLength = 0;
    }
    return errorList;
}
Error *addError(ErrorList *errorList, ErrorSeverity severity, ErrorType type)
{
    Error *error = (Error *)malloc(sizeof(Error));
    if (!error)
    {
        return NULL;
    }
    error->errorMessage = errorMessages[type];
    error->severity = severity;
    error->type = type;
    error->nextError = NULL;

    if (errorList->errorListLength == 0)
    {
        errorList->begin =
            errorList->end =
                error;
    }
    else
    {
        errorList->end->nextError = error;
        errorList->end = error;
    }

    ++errorList->errorListLength;

    return error;
}
void freeErrorList(ErrorList *errorList)
{
    Error *ptr = errorList->begin;
    Error *nextptr = NULL;
    while (ptr != NULL)
    {
        nextptr = ptr->nextError;
        free(ptr);
        ptr = nextptr;
    }
    free(errorList);
}