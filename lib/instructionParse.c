#include "instructionParse.h"
#include <stdlib.h>

InstructionType parseInstructionChar(const char instruction)
{
    switch(instruction)
    {
        case '+': return INCREMENT;
        case '-': return DECREMENT;
        case '>': return MOVE_FORWARD;
        case '<': return MOVE_BACKWARD;
        case ',': return INPUT;
        case '.': return OUTPUT;
        case '[': return CONDITIONAL_START;
        case ']': return CONDITIONAL_END;
        default: return INVALID;
    }
}

Instruction * parseInstructionString(const char * string)
{
    InstructionList instructionList;
    InstructionType type;
    Instruction instruction;

    for(size_t i = 0; string[i] != '\0'; i++)
    {
        type = parseInstructionChar(string[i]);
        if(type == INVALID)
        {
            continue;
        }
        
    }
}