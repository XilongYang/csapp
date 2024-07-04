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

float_bits float_i2f(int i) {
  // Zero
  if (i == 0) {
      return 0;
  }

  // sign bit
  unsigned sign = i & 0x80000000;

  unsigned frac = i;

  // convert negative value
  if (sign) {
      frac = 0x80000000 - (frac & 0x7FFFFFFF);
  }

  // calculate leading 0s, therefore we can get the e.
  unsigned e = 32;
  unsigned first_bit = frac & 0x80000000;
  while (!first_bit && e > 0) {
    --e;
    frac <<= 1;
    first_bit = frac & 0x80000000;
  }

  // make the leading 1 implicated.
  --e;
  frac <<= 1;

  // rounding
  unsigned validate_frac = frac >> 9;
  unsigned rounded_frac = frac & 0x1FF;
  unsigned least_validate_bit = validate_frac & 1;
  if (rounded_frac > 0x100 || (rounded_frac == 0x100 && least_validate_bit)) {
    validate_frac = (validate_frac | 0x00800000) + 1;
    if (validate_frac & 0x01000000) {
      validate_frac >>= 1;
      ++e;
    }
  }
  frac = validate_frac & 0x007FFFFF;

  // EXP
  unsigned exp = (e + 127) << 23;

  return sign | exp | frac;
}

void test(int i) {
  float except = (float) i;
  float result = bits2float(float_i2f(i));
  if (except != result) {
    printf("%x = %x : %x\n", i, float2bits(except), float2bits(result));
    printf("%12d = %12f : %12f\n", i, except, result);
  }
}

int main() {
    for (int i = INT_MIN; i < INT_MAX; ++i) {
        test(i);
    }
    return 0;
}

