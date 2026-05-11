#include <stdatomic.h>
#include <stdint.h>

struct A {
    _Atomic int32_t x;
    _Atomic int32_t y;
};

void main(void) {
    struct A a1 = {6, 7};

    void _Atomic *pav = &a1;    /* Non-compliant */
    void _Atomic *pax = &a1.x;  /* Non-compliant */
}
