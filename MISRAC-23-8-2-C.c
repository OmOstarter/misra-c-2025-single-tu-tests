#include <math.h>

#define SQRT(X) (_Generic((X),             \
                          float      : sqrtf, \
                          long double: sqrtl, \
                          default    : sqrt), (X))
                          

void test(double d, float f, long double ld, int i)
{
  (void)SQRT(d);    /* 預期：符合 MISRA 23.8（default 不在中間） */
  
}
