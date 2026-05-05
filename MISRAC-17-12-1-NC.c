#include <stdint.h>

typedef int32_t (*pfn_i)(void);  // 函數指針類型

// 函數和函數指針
extern int32_t func1(void);      // 普通函數
extern int32_t (*func2)(void);   // 函數指針

void func(void) {
    pfn_i pfn1 = &func1;         // 合規 - 使用 `&` 明確取得函數地址
    pfn_i pfn2 = func1;          // 不合規 - 未明確表示意圖

    int32_t i32a = (*pfn1)();    // 合規 - 函數指針的顯式調用
    pfn1();                      // 合規 - 函數指針的隱式調用

    if (func1 == func2) {        // 不合規 - 比較函數識別符，意圖不明確
        /* ... */
    }

    if (func1() == func2()) {    // 合規 - 比較函數的返回值
        /* ... */
    }

    if (&func1 == func2) {       // 合規 - 比較函數地址
        /* ... */
    }
}
