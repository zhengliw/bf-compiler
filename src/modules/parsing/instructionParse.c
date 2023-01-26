#include "instructionParse.h"
#include "../instructions/instructions.h"
#include <stdlib.h>
#include <string.h>

InstructionList *parseInstructionString(const char *preprocessedString)
{
    InstructionList *instructionList = newInstructionList();

    if (!instructionList)
    {
        return NULL;
    }

    for (size_t i = 0; preprocessedString[i] != '\0'; i++)
    {
        InstructionType type = instructionChar(preprocessedString[i]);
        addInstruction(instructionList, type);
    }
    return instructionList;
}