#include <stdint.h>
#include <stdio.h>

// 非合規範例：使用小型整數巨集
int main(void) {
    printf("UINT8_C(255):%d\n", UINT8_C(255));//0 1111 1111
    printf("UINT8_C(256):%d\n", UINT8_C(256));//1 0000 0000
    printf("(uint8_t)255:%d\n", (uint8_t)255);//0 1111 1111
    printf("(uint8_t)256:%d\n", (uint8_t)256);//1 0000 0000

}
