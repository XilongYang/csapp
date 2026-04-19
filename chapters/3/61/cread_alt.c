long cread_alt(long *xp) {
    static const long zero = 0;
    return *(xp ? xp : &zero);
}

