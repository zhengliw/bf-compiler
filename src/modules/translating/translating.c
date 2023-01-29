#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "translating.h"
#include "../instructions/instructions.h"
#define CODELINE_BUF_SIZE 64
#define IO_LOOP_REQUIRED_REPEAT_COUNT 4

const char *C_CODE_PREFIX =
    "#include <stdio.h>\n"
    "int main(void){"
    "int stack[4096] = {0};"
    "int *ptr = stack;";

const char *C_CODE_SUFFIX =
    "return 0;}";

const char *C_INCREMENT =
    "*ptr+=%zu;";

const char *C_DECREMENT =
    "*ptr-=%zu;";

const char *C_MOVE_FORWARD =
    "ptr+=%zu;";

const char *C_MOVE_BACKWARD =
    "ptr-=%zu;";

const char *C_OUTPUT =
    "putchar(*ptr);";

const char *C_INPUT =
    "getchar(*ptr);";

// If repeat count for input/output actions is high,
// a loop is more logical than simply repeating a
// statement n times.
const char *C_IO_N =
    "for(size_t i = 0; i < %zu; ++i){%s}";

const char *C_CONDITIONAL_START =
    "while(*ptr){";

const char *C_CONDITIONAL_END =
    "}";

char *c_action(char *buffer, InstructionType type, size_t repeat_count);
// Repeats a string with only one \0 at the end
// Repeats count - 1 times
char *repeatString(char *str, size_t count);

FILE *CtranslateInstructions(InstructionList *instructionList, const char *filename)
{
    FILE *file = fopen(filename, "w");
    char *bufptr = malloc(CODELINE_BUF_SIZE);
    if (!file || !bufptr)
    {
        return NULL;
    }
    memset(bufptr, '\0', CODELINE_BUF_SIZE);
    fprintf(file, "%s", C_CODE_PREFIX);
    for (InstructionNode *ptr = instructionList->begin; ptr != NULL; ptr = ptr->nextInstructionNode)
    {
        bufptr = c_action(bufptr, ptr->instruction.type, ptr->instruction.repeatCount);
        fprintf(file, "%s", bufptr);
        free(bufptr);
    }
    fprintf(file, "%s", C_CODE_SUFFIX);
    return file;
}

char *c_action(char *buf, InstructionType type, size_t repeatCount)
{
    char *tmp = NULL;
    memset(buf, '\0', CODELINE_BUF_SIZE * sizeof(char));
    switch (type)
    {
    case INCREMENT:
        snprintf(buf, CODELINE_BUF_SIZE, C_INCREMENT, repeatCount);
        break;
    case DECREMENT:
        snprintf(buf, CODELINE_BUF_SIZE, C_DECREMENT, repeatCount);
        break;
    case MOVE_FORWARD:
        snprintf(buf, CODELINE_BUF_SIZE, C_MOVE_FORWARD, repeatCount);
        break;
    case MOVE_BACKWARD:
        snprintf(buf, CODELINE_BUF_SIZE, C_MOVE_BACKWARD, repeatCount);
        break;
    case OUTPUT:
    case INPUT:
        if (repeatCount < IO_LOOP_REQUIRED_REPEAT_COUNT)
        {
            // If I/O instruction is not repeated as often
            snprintf(buf, CODELINE_BUF_SIZE, type == OUTPUT ? C_OUTPUT : C_INPUT);
            break;
        }
        else
        {
            // If I/O instruction is repeated a little more often
            snprintf(buf, CODELINE_BUF_SIZE, C_IO_N, repeatCount, type == OUTPUT ? C_OUTPUT : C_INPUT);
        }
    case CONDITIONAL_START:
    case CONDITIONAL_END:
        tmp = repeatString(type == CONDITIONAL_START ? C_CONDITIONAL_START : C_CONDITIONAL_END, repeatCount);
        if (tmp)
        {
            return tmp;
        }
        break;
    default:
        break;
    }
    return buf;
}

char *repeatString(const char *str, size_t count)
{
    size_t newLength = strlen(str) * count + 1;
    char *res = (char *)malloc(newLength);
    if (!res)
    {
        return NULL;
    }
    memset(str, '\0', newLength);
    for (size_t i = count; i > 0; --i)
    {
        strcat(res, str);
    }
    return res;
}