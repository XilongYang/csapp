#include <stdio.h>

int fuse(int x, int y) {
    int mask_least = (1 << 8) - 1;
    int mask_remain = ~mask_least;
    return (x & mask_least) | (y & mask_remain);
}

int main() {
    int x = 0x11223344;
    int y = 0xaabbccdd;
    printf("%x\n", fuse(x, y));
    return 0;
}

