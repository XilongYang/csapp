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
*/

#include <stdio.h>

unsigned rotate_left(unsigned x, int n) {
    unsigned left_part = x << n;
    unsigned right_part = x >> (32 - n);
    return left_part | right_part;
}

void test(unsigned x, int n) {
  printf("%x: %x\n", x, rotate_left(x, n));
}

int main() {
    test(0, 0);
    test(0, 1);
    test(0, 31);
    test(~0, 0);
    test(~0, 1);
    test(~0, 31);
    test(0x12345678, 0);
    test(0x12345678, 1);
    test(0x12345678, 31);
    return 0;
}

