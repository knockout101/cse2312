#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

extern int add32(uint32_t a, uint32_t b);

int main(int argc, char* args[])
{
    if(argc != 3)
    {
        printf("Usage: test [#1] [#2]\n");
        exit(EXIT_FAILURE);
    }
    int result = add32(atoi(args[1]), atoi(args[2]));
    printf("Result: %d\n", result);

    return 0;
}