#include <stdio.h>
#include <stdlib.h>
#include "../src/modules/instructionList/instructionList.h"
int main(void)
{
    InstructionList * testInstructionList = newInstructionList();
    if(!testInstructionList)
    {
        puts("newInstructionList failed.");
        return EXIT_FAILURE;
    }

    addInstruction(testInstructionList, INCREMENT);
    addInstruction(testInstructionList, INCREMENT);
    addInstruction(testInstructionList, DECREMENT);
    addInstruction(testInstructionList, DECREMENT);
    addInstruction(testInstructionList, DECREMENT);

    puts("Added instructions.");

    InstructionNode *ptr = testInstructionList->begin;

    for(size_t i = 0; i < testInstructionList->listLength; i++, ptr=ptr->nextInstructionNode)
    {
        printf(
            "Instruction Type: %d\n"
            "Instruction repeats %d times\n"
            "---\n",
            ptr->instruction.type, ptr->instruction.repeatCount);
    }
}