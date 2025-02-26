#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

extern int16_t maxS16(int16_t, int16_t);
extern uint32_t maxU32(uint32_t, uint32_t);
extern bool isGreaterThanU16(uint16_t x, uint16_t y); // returns 1 if x>y, 0 else
extern bool isGreaterThanS16(int16_t x, int16_t y); // returns 1 if x>y, 0 else
extern uint16_t shiftU16(uint16_t x, int8_t p); // return x*2^p for p = -31..31

int main(int argc, char *args[])
{
    if(argc != 4)
    {
        fprintf(stderr, "\nUsage: [test_code] [arg1] [arg2]\n\n");
        exit(EXIT_FAILURE);
    }
    int test_code = atoi(args[1]);
    char *endptr;
    uint16_t ua16 = atoi(args[2]), ub16 = atoi(args[3]);
    int16_t a16 = atoi(args[2]), b16 = atoi(args[3]);

    int8_t a8 = atoi(args[2]), b8 = atoi(args[3]);

    uint32_t ua32 = strtoul(args[2], &endptr, 10), ub32 = strtoul(args[3], &endptr, 10);

    switch(test_code)
    {
        case 1:
            printf("\n\t%i is the max of (%i, %i)\n\n", maxS16(a16, b16), a16, b16);
            break;
        case 2:
            printf("\n\t%" PRIu32 " is the max of (%" PRIu32", %" PRIu32 ")\n\n", maxU32(ua32, ub32), ua32, ub32);
            break;
        case 3:
            printf("\n\t%" PRIu16 " is greater than %" PRIu16 ": %s\n\n", ua16, ub16, (isGreaterThanU16(ua16, ub16) ? "true" : "false"));
            break;
        case 4:
            printf("\n\t%i is greater than %i: %s\n\n", a16, b16, (isGreaterThanS16(a16, b16) ? "true" : "false"));
            break;
        case 5:
            printf("\n\t%" PRIu16 " shifted %i: %" PRIu16 "\n\n", ua16, b8, shiftU16(ua16, b8));
            break;
        default:
            fprintf(stderr, "\n------- Incorrect test code | Check usage by calling program without CLI arguments -------\n\n");
    }
    

    return 0;
}