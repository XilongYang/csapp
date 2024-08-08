#include <stdio.h>

int is_little_endian() {
    int test = 0xff;
    unsigned char first_byte = *(unsigned char*)&test;
    return first_byte == (unsigned char)0xff;
}

int main() {
    printf("%d\n", is_little_endian());
    return 0;
}

