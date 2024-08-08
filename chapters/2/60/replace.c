#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    unsigned mask = ~(0xff << (i * 8));
    unsigned settled_byte = ((unsigned)b) << (i * 8);
    return x & mask | settled_byte;
}

int main() {
    printf("%x\n", replace_byte(0x12345678, 0, 0xbb));
    printf("%x\n", replace_byte(0x12345678, 1, 0xbb));
    printf("%x\n", replace_byte(0x12345678, 2, 0xbb));
    printf("%x\n", replace_byte(0x12345678, 3, 0xbb));
    printf("%x\n", replace_byte(0x12345678, 4, 0xbb));
    return 0;
}

