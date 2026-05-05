#include <stdalign.h>
#include <stdint.h>

// 錯誤 1: 多個對齊規範
alignas(16) alignas(8) int32_t a; // 不合規 - 兩個對齊規範

// 錯誤 2: 與規則 8.16 同時違反
alignas(16) alignas(0) int32_t b; // 不合規 - 同時違反 8.16 和 8.17

// 錯誤 3: 沒有合併不同條件的對齊要求
#if CONDITION1
    #define ALIGN_1 alignas(16)
#else
    #define ALIGN_1 alignas(8)
#endif
ALIGN_1 alignas(32) int32_t c; // 不合規 - 多個對齊規範
