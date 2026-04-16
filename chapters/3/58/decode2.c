long decode2(long x, long y, long z) {
    long r1 = y - z;
    long r2 = x * r1;
    long r3 = (r1 << 63) >> 63;
    return r2 ^ r3;
}

