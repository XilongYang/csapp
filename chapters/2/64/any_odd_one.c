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

int any_odd_one(unsigned x) {
    unsigned mask = 0x55555555u;
    return 1 && x&mask;
}

void test(unsigned x) {
    printf("%x: %d\n", x, any_odd_one(x));
}

int main() {
    test(0);
    test(1);
    test(2);
    test(6);
    test(8);
    test(12);
    return 0;
}

