#include <stdio.h>

int int_shifts_arithmetic() {
    int test = (-1 >> 1) ^ -1;
    return !test;
}

int usigned_shifts_logic() {
    unsigned test = (~0u >> 1) ^ ~0;
    return 1 && test;
}

int main() {
    printf("%d\n", int_shifts_arithmetic());
    printf("%d\n", usigned_shifts_logic());
    return 0;
}

