#include <stdio.h>
#include <stdlib.h>
#include "../src/modules/instructionList/instructionList.h"
#include "../src/modules/parsing/instructionParse.h"
#include "../src/modules/preprocessing/instructionPreprocess.h"
int main(void)
{
    puts("Supply brainfuck instructions:");

    char *buf = (char *)malloc(30 * sizeof(char));

    fgets(buf, 30, stdin);

    buf = instructionPreprocess(buf, 1);

    InstructionList *instructionList = parseInstructionString(buf);

    if (!instructionList)
    {
        puts("Instruction parsing failed.");
        return 1;
    }

    puts("Added instructions.");

    InstructionNode *ptr = instructionList->begin;

    for (size_t i = 0; i < instructionList->listLength; i++, ptr = ptr->nextInstructionNode)
    {
        printf(
            "Instruction Type: %d\n"
            "Instruction repeats %d times\n"
            "---\n",
            ptr->instruction.type, ptr->instruction.repeatCount);
    }
}