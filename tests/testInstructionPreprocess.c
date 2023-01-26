#include <stdio.h>
#include <string.h>
#include "../src/modules/preprocessing/instructionPreprocess.h"
int main(void)
{
    puts("Screw you. Here is the test.");
    char buffer[30] = {0};
    char *newline = NULL;
    while (1)
    {
        fgets(buffer, 30, stdin);
        if ((newline = strchr(buffer, '\n')) != NULL)
            *newline = '\0';
        else
            while(getchar()!='\n');
        printf("%s", instructionPreprocess(buffer, false));
        memset(buffer, '\0', 30 * sizeof(char));
        puts("\n---");
    }
    return 0;
}