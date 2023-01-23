#ifndef INSTRUCTION_LIST_H
#define INSTRUCTION_LIST_H

#include "instructions.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct 
{
    Instruction instruction;
    InstructionNode * nextInstructionNode;
} InstructionNode;

typedef struct
{
    InstructionNode * begin;
    InstructionNode * end;
    size_t listLength;
} InstructionList;

void initInstructionList(InstructionList * instructionList)
InstructionNode * addInstruction(InstructionList * instructionList, const Instruction instruction);
Instruction * instructionListArray(const InstructionList instructionList);
void freeInstructionList(InstructionList * instructionList);

#endif