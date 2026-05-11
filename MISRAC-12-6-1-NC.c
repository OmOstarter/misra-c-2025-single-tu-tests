#include <stdatomic.h>
#include <stdint.h>

typedef struct s {
    uint8_t a;
    uint8_t b;
} s_t;

_Atomic s_t astr;

int main(void) {
    s_t lstr = { 7U, 42U };

    /* Non-compliant */

    astr.b = 43U;

    // compliant
    lstr = atomic_load(&astr); //
    lstr.b = 43U;             // 
    atomic_store(&astr, lstr); // 

    /*compliant */

    lstr.a = 8U;
    astr = lstr;

    return 0;
}
