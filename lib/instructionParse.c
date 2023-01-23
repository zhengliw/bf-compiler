#include "../include/parsing/instructionParse.h"
#include <stdlib.h>

InstructionList parseInstructionString(const char * string)
{
    InstructionList instructionList;
    InstructionType type;
    Instruction instruction;

    for(size_t i = 0; string[i] != '\0'; i++)
    {
        type = instructionChar(string[i]);
        if(type == INVALID)
        {
            continue;
        }
        
    }
}