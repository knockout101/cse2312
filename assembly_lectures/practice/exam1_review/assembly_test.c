#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern int shiftMoveTest(int, int);
extern bool isOdd(int);

int main(int argc, char *args[])
{
    int test_val = atoi(args[1]);
    printf("\n%i is %s\n\n", test_val, (isOdd(test_val) ? "odd" : "even"));

    return 0;
}