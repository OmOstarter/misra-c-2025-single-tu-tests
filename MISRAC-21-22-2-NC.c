#include <tgmath.h>
#include <complex.h>

void fn2(void) {
    float          f1, f2;
    _Complex float cf1, cf2;

    f2 = sqrt(f1);    // compliant
    cf2 = sqrt(cf1);  // compliant

    f2 = ceil(f1);    // compliant
    cf2 = ceil(cf1);  /* Non-compliant */
}
