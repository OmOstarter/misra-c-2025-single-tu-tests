#include <stdint.h>

typedef int32_t (*pfn_i)(void);  // 函數指針類型

// 函數和函數指針
extern int32_t func1(void);      // 普通函數
extern int32_t (*func2)(void);   // 函數指針

void func(void) {
    pfn_i pfn1 = &func1;         // compliant
    pfn_i pfn2 = func1;          /* Non-compliant */


    int32_t i32a = (*pfn1)();    // compliant
    pfn1();                      // compliant

    if (func1 == func2) {        /* Non-compliant */

        /* ... */
    }

    if (func1() == func2()) {    // compliant
        /* ... */
    }

    if (&func1 == func2) {       // compliant
        /* ... */
    }
}
