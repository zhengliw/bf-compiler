#include <stdio.h>
int main(void){int stack[4096] = {0};int *ptr = stack; *ptr+=72;ptr+=1;*ptr+=73;ptr-=1;putchar(*ptr);ptr+=1;putchar(*ptr);return 0;}