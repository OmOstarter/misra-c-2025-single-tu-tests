#include <stdint.h>
#include <stdio.h>

int main(void) {
    uint8_t a = UINT8_C(100);  // non-compliant
    printf("a:%d\n", a);

    
    #define M(x) _Generic((x), uint8_t: "uint8_t", default: "other")
    printf("Type of UINT8_C(100): %s\n", M(UINT8_C(100))); // non-compliant

    return 0;
}
