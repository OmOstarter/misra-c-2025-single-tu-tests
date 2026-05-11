#include <math.h>

#define SQRT(X) (_Generic((X),             \
                          float      : sqrtf, \
                          long double: sqrtl, \
                          default    : sqrt), (X))
                          

void test(double d, float f, long double ld, int i)
{
  (void)SQRT(d);    /* compliant */
  
}
