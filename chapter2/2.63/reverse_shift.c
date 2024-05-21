#include <stdio.h>
#include <limits.h>

int w = sizeof(int) * 8;

unsigned srl(unsigned x, int k) {
    unsigned xsra = (int) x >> k;
    unsigned mask = (1 << (w - k)) - 1;
    return k == 0 ? xsra : xsra & mask;
}

int sra(int x, int k) {
    int xsrl = (unsigned) x >> k;
    int sign = x & (1 << (w - 1));
    int mask = ~((1 << (w - k)) - 1);
    return sign ? (xsrl | mask) : xsrl;
}

int main() {
    printf("srl:\n");
    printf("%x\n", srl(~0, 0));
    printf("%x\n", srl(~0, 1));
    printf("%x\n", srl(~0, 4));
    printf("%x\n", srl(~0, w - 1));

    printf("sra(~0):\n");
    printf("%x\n", sra(~0, 0));
    printf("%x\n", sra(~0, 1));
    printf("%x\n", sra(~0, 4));
    printf("%x\n", sra(~0, w - 1));

    printf("sra(INT_MAX):\n");
    printf("%x\n", sra(INT_MAX, 0));
    printf("%x\n", sra(INT_MAX, 1));
    printf("%x\n", sra(INT_MAX, 4));
    printf("%x\n", sra(INT_MAX, w - 1));
    return 0;
}

