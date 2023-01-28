#include <stdlib.h>
#include <string.h>
#include "translating.h"
#include "../instructions/instructions.h"
#define CODELINE_BUF_SIZE 64

const char *CODE_PREFIX =
    "#include <stdio.h>\n"
    "int main(void){"
    "int stack[4096] = {0};"
    "int *ptr = stack; ";

const char *CODE_SUFFIX =
    "return 0;}";

char * action(InstructionType type, size_t repeat_count);

FILE *translateInstructions(InstructionList *instructionList, const char *filename)
{
    FILE* file = fopen(filename, "w");
    char * bufptr;
    if(!file)
    {
        return NULL;
    }
    fprintf(file, "%s", CODE_PREFIX);
    for(InstructionNode * ptr = instructionList->begin; ptr != NULL; ptr = ptr->nextInstructionNode)
    {
        bufptr = action(ptr->instruction.type, ptr->instruction.repeatCount);
        fprintf(file, "%s", bufptr);
        free(bufptr);
    }
    fprintf(file, "%s", CODE_SUFFIX);
    return file;
}

char * action(InstructionType type, size_t repeatCount)
{
    char * buffer = (char *)malloc(CODELINE_BUF_SIZE * sizeof(char));
    if(!buffer)
    {
        return NULL;
    }
    memset(buffer, '\0', CODELINE_BUF_SIZE * sizeof(char));
    switch(type)
    {
        case INCREMENT:
            snprintf(buffer, CODELINE_BUF_SIZE, "*ptr+=%zu;", repeatCount);
            break;
        case DECREMENT:
            snprintf(buffer, CODELINE_BUF_SIZE, "*ptr-=%zu;", repeatCount);
            break;
        case MOVE_FORWARD:
            snprintf(buffer, CODELINE_BUF_SIZE, "ptr+=%zu;", repeatCount);
            break;
        case MOVE_BACKWARD:
            snprintf(buffer, CODELINE_BUF_SIZE, "ptr-=%zu;", repeatCount);
            break;
        case OUTPUT:
            snprintf(buffer, CODELINE_BUF_SIZE, "putchar(*ptr);");
            break;
        case CONDITIONAL_START:
            snprintf(buffer, CODELINE_BUF_SIZE, "while(*ptr){");
            break;
        case CONDITIONAL_END:
            snprintf(buffer, CODELINE_BUF_SIZE, "}");
            break;
    }
    return buffer;
}