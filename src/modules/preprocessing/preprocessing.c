#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "preprocessing.h"
#include "../instructions/instructions.h"

/**
 * @brief preprocess a string
 * 
 * @param instructionString 
 * @param freeInstructionStringAfterUsed 
 * @return char* 
 * 
 * This function is fail-safe. The original
 * instructionString is returned when fail.
 */
char *instructionPreprocess(char *instructionString, bool freeInstructionStringAfterUsed)
{
    size_t instructionStringLength = strlen(instructionString) + 1;
    char *preprocessedString = (char *)malloc(instructionStringLength * sizeof(char));
    size_t preprocessedStringLength;
    if (!preprocessedString)
    {
        return instructionString;
    }

    memset(preprocessedString, '\0', instructionStringLength * sizeof(char));

    for (size_t i = 0, j = 0; i <= instructionStringLength; ++i)
    {
        if (instructionChar(instructionString[i]) != INVALID)
        {
            // Skip all invalid characters
            // Don't increment j if char
            // is invalid
            preprocessedString[j] = instructionString[i];
            ++j;
        }
    }
    preprocessedStringLength = strlen(preprocessedString) + 1;
    preprocessedString = (char *)realloc(preprocessedString, preprocessedStringLength);

    if (freeInstructionStringAfterUsed)
    {
        free(instructionString);
    }

    return preprocessedString;
}