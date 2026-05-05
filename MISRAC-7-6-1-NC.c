#include <stdint.h>
#include <stdio.h>

// 非合規範例：使用小型整數巨集
int main(void) {
    uint8_t a = UINT8_C(100);  // 不合規 - 巨集展開後通常為 plain `100`，其類型為 `int`
    printf("a:%d\n", a);
    // 類型衝突範例
    #define M(x) _Generic((x), uint8_t: "uint8_t", default: "other")
    printf("Type of UINT8_C(100): %s\n", M(UINT8_C(100))); // 不合規 - 選擇 "other"，而非 "uint8_t"

    return 0;
}
