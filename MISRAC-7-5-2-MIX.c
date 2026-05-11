#include <stdint.h>

int main(void) {
    uint16_t valid = UINT16_C(123);      // compliant
    uint16_t invalid1 = UINT16_C(10UL); // non-compliant
    uint16_t invalid2 = UINT16_C(70000); // non-compliant

    return 0;
}
