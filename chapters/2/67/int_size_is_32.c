/*
* CODING RULES
*
* Available rules are marked by sign 'X'.
*
* ASSUMPTIONS
* [X] Integers are represented in two's-complement form.
* [X] Right shifts of signed data are performed arithmetically.
* [X] Data type int is w bits long. The length of w is a multiple of 8.
*
* FORBIDDEN
* [X] Conditionals (if or ?:), loops, switch statements, function calls, and macro invocations.
* [X] Division, modulus, and multiplication.
* [X] Relative comparison operations (<, >, <=, and >=).
*
* ALLOWED OPERATIONS
* [X] All bit-level and logic operations.
* [X] Left and right shifts, but only with shift amounts between 0 and w - 1.
* [X] Addition and subtraction.
* [X] Equality (==) and inequality (!=) tests. (Some of the problems do not allow these).
* [X] Integer constants INT_MIN and INT_MAX.
* [X] Casting between data types int and unsigned, either explicitly or implicitly.
*/

#include <stdio.h>
#include <stdint.h>

int bad_int_size_is_32() {
    /* Set most significant bit (msb) of 32-bit machine */
    int set_msb = 1 << 31;
    /* Shift past msb of 32-bit word */
    int beyond_msb = 1 << 32;
    return set_msb && !beyond_msb;
}

int int_size_is_32() {
    int set_msb = 1 << 15 << 15;
    int beyond_msb = set_msb;

    set_msb <<= 1;
    beyond_msb <<= 2;
    return set_msb && !beyond_msb;
}

int int_size_is_32_under_16() {
    int16_t set_msb = 1 << 14;
    set_msb <<= 14;
    int16_t beyond_msb = set_msb;

    set_msb <<= 3;
    beyond_msb <<= 4;
    return set_msb && !beyond_msb;
}

int main() {
    printf("%d\n", bad_int_size_is_32());
    printf("%d\n", int_size_is_32());
    printf("%d\n", int_size_is_32_under_16());
    return 0;
}

