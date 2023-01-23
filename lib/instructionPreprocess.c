#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "../include/preprocessing/instructionPreprocess.h"
#include "../include/instructions.h"

char * instructionPreprocess(char * instructionString)
{
    size_t instructionStringLength = strlen(instructionString) + 1;
    char * preprocessedString = malloc(instructionStringLength * sizeof(char));
    size_t preprocessedStringLength;
    if (!preprocessedString)
    {
        return NULL;
    }

    memset(preprocessedString, '\0', instructionStringLength * sizeof(char));

    for(size_t i = 0, j = 0; i <= instructionStringLength; i++)
    {
        if(instructionChar(instructionString[i]) != INVALID)
        {
            preprocessedString[j] = instructionString[i];
            j++;
        }
    }
    preprocessedStringLength = strlen(preprocessedString) + 1;
    preprocessedString = realloc(preprocessedString, preprocessedStringLength);
    return preprocessedString;
}