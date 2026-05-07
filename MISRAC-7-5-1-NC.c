#include <stdint.h>

int main(void) {
    // Non-compliant integer constant macro arguments
    uint32_t u1 = UINT32_C(10UL);    // Non-compliant - constant has suffix
    uint32_t u2 = UINT32_C(10.0);    // Non-compliant - floating-point constant
    uint16_t u3 = UINT16_C(-1);      // Non-compliant - negative value out of unsigned range
    int32_t s1 = INT32_C(-2.5);      // Non-compliant - floating-point constant
    int32_t s2 = INT32_C(2147483648); // Non-compliant - exceeds 32-bit signed integer range

    // Values exceeding the corresponding bit-width
    uint16_t u4 = UINT16_C(0x10000); // Non-compliant - exceeds 16-bit unsigned integer range
    int16_t s3 = INT16_C(0x8000);    // Non-compliant - exceeds 16-bit signed integer range

    // Compliant usage for comparison
    uint32_t u5 = UINT32_C(123);     // Compliant
    int32_t s4 = INT32_C(-123);      // Compliant

    return 0;
}
