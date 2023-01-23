#ifndef INSTRUCTION_PARSE_H
#define INSTRUCTION_PARSE_H

#include "instructions.h"
#include "instructionList.h"

InstructionType parseInstructionChar(const char instruction);
InstructionList parseInstructionString(const char * string);

#endif