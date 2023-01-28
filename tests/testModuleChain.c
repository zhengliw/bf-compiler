#include "../src/modules/preprocessing/preprocessing.h"
#include "../src/modules/parsing/parsing.h"
#include "../src/modules/checking/checking.h"
#include "../src/modules/translating/translating.h"

#include <limits.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char filename[FILENAME_MAX] = {0};
    puts("BF filename here:");
    fgets(filename, FILENAME_MAX, stdin);
    char * newline = strchr(filename, '\n');
    if(newline) *newline = '\0';

    FILE * fp = fopen(filename, "r");

    if(!fp)
    {
        puts("Something went wrong. Bye!");
        return 1;
    }

    fseek(fp, 0L, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    char * buffer = malloc((size + 1) * sizeof(char));

    if(!buffer)
    {
        puts("Your memory bad. Bye.");
        return 1;
    }

    memset(buffer, '\0', size+1);

    puts("File content:");
    puts("--- BEGIN ---");

    for(size_t i = 0; i < size; i++)
    {
        buffer[i] = getc(fp);
        putchar(buffer[i]);
    }

    puts("\n--- END ---");

    fclose(fp);

    buffer = instructionPreprocess(buffer, true);

    InstructionList * iList = parseInstructionString(buffer);

    if (!iList)
    {
        puts("iList failed :(");
        free(buffer);
        return 1;
    }

    ErrorList * elist = checkInstructions(iList, 1);

    if(elist->begin != NULL)
    {
        printf("elist->begin: %p\n", elist->begin);
        for(Error * ptr = elist->begin; ptr!=NULL; ptr = ptr->nextError)
        {
            printf("%s\n"
            "Severity: %d\t"
            "Type: %d", ptr->errorMessage, ptr->severity, ptr->type);
        }
        puts("Keep going? y/n");
        if(getchar() == 'n')
        {
            free(buffer);
            free(iList);
            free(elist);
            return 1;
        }
        getchar();
    }

    for(InstructionNode * ptr = iList->begin; ptr!=NULL; ptr=ptr->nextInstructionNode)
    {
        printf(
            "Instruction Type: %d\n"
            "Instruction repeats %d times\n"
            "---\n",
            ptr->instruction.type, ptr->instruction.repeatCount);
    }

    memset(filename, '\0', FILENAME_MAX);
    puts("Generated code filename here:");
    fgets(filename, FILENAME_MAX, stdin);
    newline = strchr(filename, '\n');
    if(newline) *newline = '\0';

    fp = translateInstructions(iList, filename);

    if(fp == NULL)
    {
        puts("Oh no. fp failed.");
    }

    puts("Done. If the program didn't fail, congrats, you are finished.");
}

