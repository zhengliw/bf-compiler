#ifndef TRANSLATING_H
#define TRANSLATING_H

#include <stdio.h>
#include "../instructionList/instructionList.h"

FILE *translateInstructions(InstructionList *instructionList, char *filename);

const char *CODE_PREFIX =
    "#include <stdio.h>\n"
    "int main(void){";

const char *CODE_SUFFIX =
    "return 0;}";

#endif