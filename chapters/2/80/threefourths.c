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

/*
* Consider the number as two parts: the first 30 bits f and the least 2 bits l.
* x * 3 / 4 = (f + l) * 3 / 4 = f * 3 / 4 + l * 3 / 4
* So that, we can safely divide f by 4 since its least 2 bits is 0.
* Vice versa, we can safely multiple l.
* That is, the computation can safely process by this way for correct randing and without overflow:
* x = (f / 4) * 3 + (l * 3) / 4
*/
int threefourths(int x) {
    int sign = (x >> (sizeof(int) * 8 - 1)) & 1;
    int bias = (sign << 2) - sign;

    int f = x & ~3;
    int l = x & 3;

    f = ((f >> 2) << 1) + (f >> 2);

    l = (l << 1) + l;
    l = (l + bias) >> 2;

    return f + l;
}

void test(int x) {
    int except = (int)((double) x * 3 / 4);
    int result = threefourths(x);
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

