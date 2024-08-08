#include <stdio.h>
#include <inttypes.h>

int signed_high_prod(int x, int y) {
    int64_t result = (int64_t) x * y;
    return result >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
    unsigned sign_x = x >> 31;
    unsigned sign_y = y >> 31;

    /*
     * There is a precondition for the correctness of the principle:
     * Bit-level equivalence of unsigned and two's-complement multiplication.
     * That is, the result must be truncated to the word-size.
     *
     * If x' = T2U(x) = x + x_w-1 * 2^w, y' = T2U(y) = y + y_w-1 * 2^w, then
     * x' *u y' = (x' * y') mod 2^w
     *          = (x * y + (x * y_w-1) * 2^w + (y * x_w-1) * 2^w + x_w-1 * y_w-1 * 2^2w) mod 2^w
     *          = (x * y) mod 2^w
     * Then the bit-level representation is same as the U2T((x * y) mod 2^w) = x *t y.
     *
     * But, when we consider the higher 32-bit, in other word, the truncated part.
     * It is necessary to save the higher 32-bit, so that we can't truncated the result
     * by 32 bit but by 64 bit.
     *
     * Thus,
     * x' *u y' = (x' * y') mod 2^2w = (x * y + (x * y_w-1 + y * x_w-1) * 2^w) mod 2^2w
     */
    return signed_high_prod(x, y) + sign_x * y + sign_y * x;
}

unsigned another_unsigned_high_prod(unsigned x, unsigned y) {
    uint64_t result = (uint64_t) x * y;
    return result >> 32;
}

void check(int x, int y) {
    printf("%d * %d: %x, %x, %x: ", x, y, signed_high_prod(x, y), unsigned_high_prod(x, y), another_unsigned_high_prod(x, y));
    printf("%s\n", (unsigned_high_prod(x, y) == another_unsigned_high_prod(x, y) ? "OK" : "NG"));
}

int main() {
    check(1, 1);
    check(0, 1);
    check(-2, 2);
    check(2, 2);
    check(-2, -2);
    return 0;
}

