#include <stdatomic.h>
#include <stdint.h>

typedef struct s {
    uint8_t a;
    uint8_t b;
} s_t;

_Atomic s_t astr;

int main(void) {
    s_t lstr = { 7U, 42U };

    // 非合規 - 直接存取結構成員，繞過保護機制
    astr.b = 43U;

    // 合規 - 使用標準函數存取整個原子物件
    lstr = atomic_load(&astr); // 加載整個原子物件
    lstr.b = 43U;             // 修改本地變數
    atomic_store(&astr, lstr); // 存回整個原子物件

    // 合規 - 使用賦值運算符處理整個原子物件
    lstr.a = 8U;
    astr = lstr;

    return 0;
}
