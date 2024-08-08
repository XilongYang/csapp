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
#include <limits.h>

int mul3div4(int x) {
    int sign = (x >> (sizeof(int) * 8 - 1)) & 1;
    int bias = (sign << 2) - sign;

    x = (x << 1) + x;
    return (x + bias) >> 2;
}

void test(int x) {
    int except = (int)((double) x * 3 / 4);
    int result = mul3div4(x);
    printf("Test: %6d * 3 / 4 = %d\n", x, except);
    printf("Result: %s, %d\n", (result == except ? "OK" : "NG"), result);
}

int main() {
    for (int i = -20; i <= 20; ++i) {
        test(i);
        test(i);
    }
    test(INT_MAX);
    test(INT_MIN);
    return 0;
}

