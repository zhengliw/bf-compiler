#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "instructionPreprocess.h"
#include "instructions.h"

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

    for(size_t i = 0; i < instructionStringLength; i++)
    {
        if(instructionChar(instructionString[i]) != INVALID)
        {
            preprocessedString[i] = instructionString[i];
        }
    }
    preprocessedStringLength = strlen(preprocessedString) + 1;
    preprocessedString = realloc(preprocessedString, preprocessedStringLength);
    return preprocessedString;
}