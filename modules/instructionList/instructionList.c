#include <stdlib.h>
#include <stdio.h> // NULL
#include "instructionList.h"

InstructionList *newInstructionList(void)
{
    InstructionList *instructionList = (InstructionList *)malloc(sizeof(InstructionList));
    if (instructionList)
    {
        instructionList->begin = NULL;
        instructionList->end = NULL;
        instructionList->listLength = 0;
    }
    return instructionList;
}

InstructionNode *addInstruction(InstructionList *instructionList, const InstructionType instructionType)
{
    if (instructionList->end != NULL && instructionList->end->instruction.type == instructionType)
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

    ++instructionList->listLength;

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
    free(instructionList);
}