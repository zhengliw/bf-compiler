#include <stdio.h>
#include "../include/preprocessing/instructionPreprocess.h"
int main(void)
{
    puts("Screw you. Here is the test.");
    char buffer[30] = {0};
    while(1)
    {
        fgets(buffer, 30, stdin);
        puts(instructionPreprocess(buffer));
    }
    return 0;
}