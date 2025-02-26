#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern bool compare(int, int);
extern bool isNegative(int);

int main(int argc, char *args[])
{
    int a = atoi(args[1]), b = atoi(args[2]);

    char *res = (compare(a, b) ? "true" : "false");

    printf("\n%i is %s", a, (isNegative(a) ? "negative" : "positive"));
    printf(" & %i is %s\n", b, (isNegative(b) ? "negative" : "positive"));
    printf("%i == %i is %s\n\n", a, b, res);

    return 0;
}