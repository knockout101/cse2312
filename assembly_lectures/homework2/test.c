#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct
{
    uint32_t low;
    uint32_t high;
} uint64_t_parts;

extern uint32_t subU32(uint32_t x, uint32_t y); // returns x-y                                      X
extern int32_t subS32(int32_t x, int32_t y); // returns x-y                                         X
extern uint64_t addU32_U64(uint32_t x, uint32_t y); // returns x+y                                  X
extern uint64_t addU64(uint64_t x, uint64_t y); // returns x+y                                      X
extern int32_t shiftRightS32 (int32_t x, uint8_t p); // returns x >> p = x*2^(-p) for p = 0..31     X
extern uint32_t shiftRightU32 (uint32_t x, uint8_t p); // returns x >> p = x*2^(-p) for p = 0..31   X
extern int32_t shiftLeftS32 (int32_t x, uint8_t p); // returns x << p = x*2^p for p = 0..31         X

int main(int argc, char* args[])
{
    if(argc != 4)
    {
        fprintf(stderr, "Usage: ./test [test #] [value1] [value2]\n");
        exit(EXIT_FAILURE);
    }
    // Result storage
    uint32_t ures = 0;
    int32_t res = 0;
    uint64_t ures64 = 0;
    int64_t res64 = 0;
    // Storing cli arguments
    char *endptr;
    uint8_t shift_val = atoi(args[3]);
    uint32_t ua = strtoul(args[2], &endptr, 10), ub = strtoul(args[3], &endptr, 10);
    int32_t a = atoi(args[2]), b = atoi(args[3]);
    uint64_t ua64 = strtoull(args[2], &endptr, 10), ub64 = strtoull(args[3], &endptr, 10);
    int64_t a64 = strtoll(args[2], &endptr, 10), b64 = strtoll(args[3], &endptr, 10);
    // Test code check
    switch(atoi(args[1]))
    {
        case 1:
            ures = subU32(ua, ub);
            printf("SubU32:\n\t%u - %u = %u\n", ua, ub, ures);
            break;
        case 2:
            res = subS32(a, b);
            printf("SubS32:\n\t%i - %i = %i\n", a, b, res);
            break;
        case 3:
            // addU32_U64 takes in uint32_t values and returns a uint64_t
            ures64 = addU32_U64(ua, ub);
            printf("AddU32_U64:\n\t%u + %u = %" PRIu64 "\n", ua, ub, ures64);
            break;
        case 4:
            // When passing 64-bit number, R0 is lower 32 and R1 is the upper 32
            ures64 = addU64(ua64, ub64);
            printf("AddU64:\n\t%" PRIu64 " + %" PRIu64 " = %" PRIu64 "\n", ua64, ub64, ures64);
            break;
        case 5:
            res = shiftRightS32(a, shift_val);
            printf("ShiftRightS32:\n\t%i >> %i = %i\n", a, shift_val, res);
            break;
        case 6:
            ures = shiftRightU32(ua, shift_val);
            printf("ShiftRightU32:\n\t%" PRIu32 " >> %i = %" PRIu32 "\n", ua, shift_val, ures);
            break;
        case 7:
            res = shiftLeftS32(a, shift_val);
            printf("ShiftLeftS32:\n\t%i << %i = %i\n", a, shift_val, res);
        default:
            fprintf(stderr, "Failed to give proper test code\n");
            exit(EXIT_FAILURE);
    }      

    return 0;
}