// Uses only left and right shifts, along with one subtractions.

#include <stdio.h>

typedef unsigned packed_t;

int xbyte_failed(packed_t word, int bytenum) {
    return (word >> (bytenum << 3)) & 0xFF;
}

int xbyte(packed_t word, int bytenum) {
    return ((int)word << ((3 - bytenum) << 3)) >> 24;
}

int main() {
    printf("%x\n", xbyte(0xabcd5678, 0));
    printf("%x\n", xbyte(0xabcd5678, 1));
    printf("%x\n", xbyte(0xabcd5678, 2));
    printf("%x\n", xbyte(0xabcd5678, 3));
    return 0;
}

