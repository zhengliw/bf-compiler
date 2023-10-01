/*
 * The MIT License (MIT)
 * bf-compiler
 * Copyright (c) 2023 Zhengli Wang
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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