#include <stdatomic.h>
#include <stdint.h>

struct A {
    _Atomic int32_t x;
    _Atomic int32_t y;
};

void main(void) {
    struct A a1 = {6, 7};

    _Atomic int32_t *pax = &a1.x;  /* compliant */
}
