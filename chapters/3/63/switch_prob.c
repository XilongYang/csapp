long switch_prob(long x, long n) {
    long result = x;
    switch(n) {
    case 60: // a1
    case 62: // a1
      result = 8 * x;
      break;
    case 63: // aa
      result = x >> 3;
      break;
    case 64: // b2
      x = (x << 4) - x;
    case 65: // bf
      x *= x;
    case 61: // c3
    default:
      result = x + 75;
    }
    return result;
}
