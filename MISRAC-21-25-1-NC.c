#include <stdatomic.h>

typedef struct s {
    uint8_t a;
    uint8_t b;
} s_t;

_Atomic s_t astr;

void main(void) {
    s_t lstr = {7, 42};

    atomic_init(&astr, lstr);                                    // 初始化

    lstr = atomic_load_explicit(&astr, memory_order_relaxed);    // non-compliant
    lstr.b = 43;
    atomic_store_explicit(&astr, lstr, memory_order_release);    // non-compliant
}
