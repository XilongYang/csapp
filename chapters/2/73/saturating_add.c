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

int saturating_add(int x, int y) {
    int w = sizeof(int) << 3;
    int sign_x = (unsigned) x >> (w - 1);
    int sign_y = (unsigned) y >> (w - 1);

    int result = x + y;
    int sign_result = (unsigned) result >> (w - 1);

    // Result is overflow only if the sign of x equals the sign of y, and the sign of x (same as y) not equals the sign of result.
    // Figure out 1 when it's overflow, and 0 otherwise.
    int overflow_flag = !sign_x^sign_y && sign_x^sign_result;

    overflow_flag && sign_result && (result = INT_MIN);
    overflow_flag && !sign_result && (result = INT_MAX);

    return result;
}

int main() {
    printf("%d\n", saturating_add(0, 0));
    printf("%d\n", saturating_add(0, 1));
    printf("%d\n", saturating_add(1, 0));
    printf("%d\n", saturating_add(1, 1));
    printf("%d\n", saturating_add(1, -1));
    printf("%d\n", saturating_add(INT_MAX, INT_MIN));
    printf("%d\n", saturating_add(INT_MAX, 1));
    printf("%d\n", saturating_add(INT_MIN, -1));
    printf("%d\n", saturating_add(INT_MAX, INT_MAX));
    printf("%d\n", saturating_add(INT_MIN, INT_MIN));
    return 0;
}

