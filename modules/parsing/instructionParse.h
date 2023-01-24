#ifndef INSTRUCTION_PARSE_H
#define INSTRUCTION_PARSE_H

#include "../instructions/instructions.h"
#include "../instructionList/instructionList.h"

InstructionList *parseInstructionString(const char *string);

#endif