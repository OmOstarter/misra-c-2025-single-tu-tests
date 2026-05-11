#include <tgmath.h>

void fn1(void) {
    float   f1, f2;
    int     i1, i2;
    char    c1, c2;
    void   *p1, *p2;

    f2 = sqrt(f1);    // compliant
    i2 = sqrt(i1);    // compliant
    c2 = sqrt(c1);    /* Non-compliant */
    p2 = sqrt(p1);    /* Non-compliant */
}
