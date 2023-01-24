#include <stdlib.h>
#include "instructionList.h"

InstructionNode *addInstruction(InstructionList *instructionList, Instruction instruction)
{
    InstructionNode *node = malloc(sizeof(InstructionNode));
    if (!node)
    {
        return NULL;
    }
    node->instruction = instruction;
    node->nextInstructionNode = NULL;

    if (instructionList->listLength == 0)
    {
        instructionList->begin =
            instructionList->end =
                node;
    }
    else
    {
        instructionList->end->nextInstructionNode = node;
        instructionList->end = node;
    }

    return node;
}

void freeInstructionList(InstructionList *instructionList)
{
    InstructionNode *ptr = instructionList->begin;
    InstructionNode *nextptr = NULL;
    while (ptr != NULL)
    {
        nextptr = ptr->nextInstructionNode;
        free(ptr);
        ptr = nextptr;
    }
}