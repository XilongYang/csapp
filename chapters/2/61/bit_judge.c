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
* [ ] Equality (==) and inequality (!=) tests. (Some of the problems do not allow these).
* [X] Integer constants INT_MIN and INT_MAX.
* [X] Casting between data types int and unsigned, either explicitly or implicitly.
*/

#include <stdio.h>
#include <limits.h>

int mask_least = 0xff;
int mask_most = 0xff << ((sizeof(int) - 1) << 3);

int any_bit_equals_1(int x) {
    return 0 || x;
}

int any_bit_equals_0(int x) {
    return 0 || ~x;
}

int any_bit_in_least_byte_equals_1(int x) {
    return 0 || (x & mask_least);
}

int any_bit_in_most_byte_equals_0(int x) {
    return 0 || (~x & mask_most);
}

void test(int x, int (*func)(int)) {
    printf("%x: %d\n", x, func(x));
}

int main() {
    printf("Any bit == 1:\n");
    test(0x00, &any_bit_equals_1);
    test(0x1000, &any_bit_equals_1);

    printf("Any bit == 0:\n");
    test(0x00, &any_bit_equals_0);
    test(0x1000, &any_bit_equals_0);
    test(-1, &any_bit_equals_0);

    printf("Any bit in least byte == 1:\n");
    test(0x00, &any_bit_in_least_byte_equals_1);
    test(0x10, &any_bit_in_least_byte_equals_1);
    test(0x1000, &any_bit_in_least_byte_equals_1);

    printf("Any bit in most byte == 0:\n");
    test(-1, &any_bit_in_most_byte_equals_0);
    test(INT_MAX, &any_bit_in_most_byte_equals_0);
    test(mask_most, &any_bit_in_most_byte_equals_0);
    test(INT_MAX & mask_most, &any_bit_in_most_byte_equals_0);
    return 0;
}

