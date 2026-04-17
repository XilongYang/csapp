long loop_direct(long x, int n)
{
  long a = 1;
  long b = 0;
  while (a != 0) {
    long rx = x & a;
    b = rx | b;
    a = a << (n & 0xFF);
  }
  return b;
}

long loop(long x, long n) {
  long result = 0;
  long mask;
  for (mask = 1; mask != 0; mask = mask << (n & 63)) {
      result |= x & mask;
  }
  return result;
}

