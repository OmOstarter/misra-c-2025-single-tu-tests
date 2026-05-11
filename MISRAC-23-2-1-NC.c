#include <stdint.h>

typedef int16_t STATE;
STATE s;
int f(void){ return 0; }

// compliant
_Static_assert( _Generic(s, int32_t:0, default:1), "x" );

// non-compliant
_Static_assert( _Generic(++s, int32_t:0, default:1), "x" );

// non-compliant
_Static_assert( _Generic(f(), int:0, default:1), "x" );
