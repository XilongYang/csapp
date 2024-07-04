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

float_bits float_negate(float_bits f) {
  unsigned sign_reverse_mask = 0x80000000;
  unsigned exp = (f >> 23) & 0xFF;
  unsigned frac = f & 0x007FFFFF;
  return (frac && exp == 0xFF) ? f : f ^ sign_reverse_mask;
}

void test(float f) {
  float except = isnan(f) ? f : -f;
  float result = bits2float(float_negate(float2bits(f)));
  if (isnan(except) && isnan(result)) {
    float_bits sign_mask = 0x80000000;
    except = bits2float(float2bits(except) & sign_mask);
    result = bits2float(float2bits(result) & sign_mask);
  }
  if (except != result) {
    printf("Test %f, %f : %f, %s\n", f, except, result, (except == result ? "OK" : "NG"));
  }
}

int main() {
    for (float_bits f = 0; f < UINT_MAX; ++f) {
        test(bits2float(f));
    }
    return 0;
}

