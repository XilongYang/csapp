#include <stdio.h>
#include <math.h>
#include <limits.h>

typedef unsigned float_bits;

float bits2float(float_bits f) {
  return *(float*)&f;
}

float_bits float2bits(float f) {
  return *(float_bits*)&f;
}

int float_f2i(float_bits f) {
  unsigned sign = f >> 31;
  unsigned exp = (f >> 23) & 0xFF;
  unsigned frac = f & 0x007FFFFF;

  int result = 0x80000000;

  if (exp == 0xFF) {
    // NaN, Inf
    return 0x80000000;
  } else if (exp == 0) {
    // Denormalized.
    return 0;
  } else if (exp != 0) {
    // Normalized
    int bias = 127;
    int e = exp - bias;
    if (e < 0) {
        return 0;
    } else if (e >= 31) {
        return 0x80000000;
    }
    frac |= 0x00800000;
    result = e > 23 ? (frac << (e - 23)) : (frac >> (23 - e));
  }

  // Negative value
  if (sign) {
    result = (0x80000000 - result) | 0x80000000;
  }

  return result;
}

void test(float f) {
  int except = (int) f;
  int result = float_f2i(float2bits(f));
  if (except != result) {
    printf("%x = %x : %x\n", float2bits(f), except, result);
    printf("%.50f = %12d : %12d\n", f, except, result);
  }
}

int main() {
    for (float_bits f = 0; f < UINT_MAX; ++f) {
        test(bits2float(f));
    }
    return 0;
}

