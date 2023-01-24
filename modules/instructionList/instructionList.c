#include <stdlib.h>
#include "instructionList.h"

InstructionList *newInstructionList(void)
{
    InstructionList *instructionList = malloc(sizeof(InstructionList));
    if(instructionList)
    {
        instructionList->begin = NULL;
        instructionList->end = NULL;
        instructionList->listLength = 0;
    }
    return instructionList;
}

InstructionNode *addInstruction(InstructionList *instructionList, const InstructionType instructionType)
{
    if(instructionList->end->instruction.type = instructionType)
    {
        ++instructionList->end->instruction.repeatCount;
        return instructionList->end;
    }
    
    InstructionNode *node = malloc(sizeof(InstructionNode));
    if (!node)
    {
        return NULL;
    }
    node->instruction.type = instructionType;
    node->instruction.repeatCount = 1;
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