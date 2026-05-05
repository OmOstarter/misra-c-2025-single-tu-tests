#include <stdint.h>

int main(void) {
    uint32_t compliant1 = UINT32_C(10);       // 合規
    uint32_t compliant2 = -INT32_C(2);       // 合規
    uint32_t non_compliant1 = UINT32_C(10U); // 不合規，參數帶後綴
    uint16_t non_compliant2 = UINT16_C(70000); // 不合規，超出範圍
    uint32_t non_compliant3 = UINT32_C(10.0);  // 不合規，浮點數
    return 0;
}
