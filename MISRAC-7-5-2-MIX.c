#include <stdint.h>

int main(void) {
    uint16_t valid = UINT16_C(123);      // 合法
    uint16_t invalid1 = UINT16_C(10UL); // 不合法 - 帶後綴
    uint16_t invalid2 = UINT16_C(70000); // 不合法 - 超出範圍

    return 0;
}
