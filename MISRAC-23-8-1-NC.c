/* test-23-8.c */
#include <math.h>

#define SQRT(X) (_Generic((X),             \
                          float      : sqrtf, \
                          default    : sqrt,  \
                          long double: sqrtl) (X))

void test(double d, float f, long double ld, int i)
{
  (void)SQRT(d);    /* non-compliant */
  
}
