#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_short(short s) {
    show_bytes((byte_pointer)&s, sizeof(s));
}

void show_long(long l) {
    show_bytes((byte_pointer)&l, sizeof(l));
}

void show_double(double d) {
    show_bytes((byte_pointer)&d, sizeof(d));
}

int main() {
    int x = 0xabcd;
    show_bytes((byte_pointer)&x, sizeof(x));

    show_short(256);
    show_long(65536);
    show_double(2.75);
    return 0;
}

