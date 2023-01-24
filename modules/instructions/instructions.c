#include "instructions.h"

InstructionType instructionChar(const char instruction)
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