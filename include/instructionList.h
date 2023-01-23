#ifndef INSTRUCTION_LIST_H
#define INSTRUCTION_LIST_H

#include "instructions.h"
#include <stdbool.h>
#include <stddef.h>

struct instructionNode
{
    Instruction instruction;
    struct instructionNode *nextInstructionNode;
};

typedef struct instructionNode InstructionNode;

struct instructionList
{
    InstructionNode *begin;
    InstructionNode *end;
    size_t listLength;
};

typedef struct instructionList InstructionList;

void initInstructionList(InstructionList *instructionList);
InstructionNode *addInstruction(InstructionList *instructionList, const Instruction instruction);
Instruction *instructionListArray(const InstructionList instructionList);
void freeInstructionList(InstructionList *instructionList);

#endif