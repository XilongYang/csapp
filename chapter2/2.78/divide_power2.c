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

int divide_power2(int x, int k) {
    int sign = (x >> (sizeof(int) * 8 - 1)) & 1;
    int bias = (sign << k) - sign;
    return (x + bias) >> k;
}

void test(int x, int k) {
    int except = x / (1 << k);
    int result = divide_power2(x, k);
    printf("Test: %6d / 2^%2d = %d\n", x, k, except);
    printf("Result: %s, %d\n", (result == except ? "OK" : "NG"), result);
}

int main() {
    for (int i = 0; i <= 10; ++i) {
        test(10000, i);
        test(-10000, i);
    }
    return 0;
}
