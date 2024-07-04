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

float_bits float_twice(float_bits f) {
  unsigned sign = f >> 31;
  unsigned exp = (f >> 23) & 0xFF;
  unsigned frac = f & 0x007FFFFF;

  if (exp == 0xFF) {
    // NaN, Inf
    return f;
  } else if (exp == 0 && frac != 0) {
    // Denormalized.
    exp = frac >> 22 ;
    frac = (frac << 1) & 0x007FFFFF;
  } else if (exp != 0) {
    // Normalized
    exp = (exp + 1) & 0xFF;
    frac = exp == 0xFF ? 0 : frac;
  }

  return sign << 31 | exp << 23 | frac;
}

void test(float f) {
  float except = isnan(f) ? f : f * 2;
  float result = bits2float(float_twice(float2bits(f)));
  if (isnan(except) && isnan(result)) {
    float_bits sign_mask = 0x80000000;
    except = bits2float(float2bits(except) & sign_mask);
    result = bits2float(float2bits(result) & sign_mask);
  }
  if (except != result) {
    printf("%x * 2 = %x : %x\n", float2bits(f), float2bits(except), float2bits(result));
    printf("%.50f * 2 = %.50f : %.50f\n", f, except, result);
  }
}

int main() {
    for (float_bits f = 0; f < UINT_MAX; ++f) {
        test(bits2float(f));
    }
    return 0;
}

