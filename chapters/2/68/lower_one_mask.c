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

int lower_one_mask(int n) {
  int half_n = n >> 1;
  int least_n = n - half_n;
  int mask = ~0;
  mask <<= half_n;
  mask <<= least_n;
  return ~mask;
}

int main() {
    printf("%x\n", lower_one_mask(1));
    printf("%x\n", lower_one_mask(2));
    printf("%x\n", lower_one_mask(sizeof(int) * 8 - 1));
    printf("%x\n", lower_one_mask(sizeof(int) * 8));
    return 0;
}

