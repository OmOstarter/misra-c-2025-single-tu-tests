#include <stdint.h>

int main(void) {
    uint32_t compliant1 = UINT32_C(10);       // compliant
    uint32_t compliant2 = -INT32_C(2);       // compliant
    uint32_t non_compliant1 = UINT32_C(10U); // non-compliant 
    uint16_t non_compliant2 = UINT16_C(70000); // non-compliant 
    uint32_t non_compliant3 = UINT32_C(10.0);  // non-compliant 
    return 0;
}
