#include <stdint.h>

typedef int16_t STATE;
STATE s;
int f(void){ return 0; }

/* 合規：無副作用 */
_Static_assert( _Generic(s, int32_t:0, default:1), "x" );

/* 不合規：++ 有副作用 */
_Static_assert( _Generic(++s, int32_t:0, default:1), "x" );

/* 不合規：函式呼叫視為副作用 */
_Static_assert( _Generic(f(), int:0, default:1), "x" );
