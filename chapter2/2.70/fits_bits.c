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

int fits_bits(int x, int n) {
    int signal = x >> (n - 1);
    return signal == 0 || signal == -1;
}

void test(int x, int n) {
    printf("x:%d, n:%d, result:%d\n", x, n, fits_bits(x, n));
}

int main() {
    test(0, 1);
    test(1, 1);
    test(-1, 1);
    test(0, 8);
    test(1, 8);
    test(127, 8);
    test(128, 8);
    test(-1, 8);
    test(-127, 8);
    test(-128, 8);
    test(-129, 8);
    return 0;
}

