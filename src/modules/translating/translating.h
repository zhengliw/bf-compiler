#ifndef TRANSLATING_H
#define TRANSLATING_H

#include <stdio.h>
#include "../instructionList/instructionList.h"

FILE *translateInstructions(InstructionList *instructionList, const char *filename);

#endif