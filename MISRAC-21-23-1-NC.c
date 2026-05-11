#include <tgmath.h>

void f(void) {
    float   f1, f2;
    double  d1, d2;

    f2 = pow(f1, f2);            // compliant
    d2 = pow(d1, d2);            // compliant

    f2 = pow(f1, d2);            // non-compliant
    f2 = pow(f1, (float)d2);     // compliant
}

void g(void) {
    short s16;
    int   i32;
    long  l32;

    i32 = pow(s16, i32);         // compliant
    i32 = pow(i32, l32);         // non-compliant

    i32 = pow(s16, 10);          // compliant
    i32 = pow(10u, 110ul);       // non-compliant
}
