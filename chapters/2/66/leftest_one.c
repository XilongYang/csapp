/*
* CODING RULES
*
* Available rules are marked by sign 'X'.
*
* ASSUMPTIONS
* [X] Integers are represented in two's-complement form.
* [X] Right shifts of signed data are performed arithmetically.
* [X] Data type int is 32 bits long.
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
* [X] Should contain a total of at most 15 arithmetic, bitwise and logical operations.
*/

#include <stdio.h>

unsigned leftest_one(unsigned x) {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return (x >> 1) + (x & 1);
}

int main() {
    printf("%x\n", leftest_one(0x00));
    printf("%x\n", leftest_one(0x01));
    printf("%x\n", leftest_one(0x03));
    printf("%x\n", leftest_one(0x05));
    printf("%x\n", leftest_one(0x07));
    printf("%x\n", leftest_one(0x80000000));
    printf("%x\n", leftest_one(0xffffffff));
    return 0;
}

