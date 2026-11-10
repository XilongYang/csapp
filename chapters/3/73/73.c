#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef enum { NEG, ZERO, POS, OTHER } range_t;

range_t find_range(float x);

const char* show_enum[4] = {"NEG", "ZERO", "POS", "OTHER"};

float uint2float(uint32_t x) {
    union {uint32_t u; float f;} v = {.u = x};
    return v.f;
}

range_t except_range(float x) {
    int result;
    if (x < 0)
        result = NEG;
    else if (x == 0)
        result = ZERO;
    else if (x > 0)
        result = POS;
    else
        result = OTHER;
    return result;
}

int main(void) {
    uint32_t start = 0; 
    uint32_t end   = ~0; 
    do {
        float f = uint2float(start);
        const char* result = show_enum[find_range(f)];
        const char* except = show_enum[except_range(f)];
        if (strcmp(result, except)) {
            printf("%f(0x%08x) -> %s : %s\n", f, start, result, except);
        }
        ++start;
    } while (start < end);
    return 0;
}
