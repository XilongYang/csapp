#include <stdio.h>

int is_little_endian() {
    int test = 0xff;
    printf("%x\n", test);
    unsigned char first_byte = *(unsigned char*)&test;
    printf("%.2x\n", first_byte);
    return first_byte != (unsigned char)0xff;
}

int main() {
    printf("%d\n", is_little_endian());
    return 0;
}

