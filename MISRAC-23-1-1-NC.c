#include <stdint.h>
#include <stdio.h>
/* Non-compliant：直接寫 _Generic */
int32_t x = 0;
int32_t y = _Generic(x, int32_t:1, float:2);

int handle_int32 (int32_t v) { return v+1; }
int handle_float (float v)   { return (int)(v+2); }
int handle_any   (int v)     { return v; }

/* Compliant*/
#define arith(X) ( _Generic((X), \
                        int32_t: handle_int32, \
                        float:   handle_float, \
                        default: handle_any)(X) )

/* Non-compliant
*/
#define maybe_inc(Y) ( _Generic(x           \
                    , int32_t:1             \
                    , default:0) + (Y) )

int main(void)
{
    int a = arith(x);        /* OK：不該警告 */
    int b = maybe_inc(5);    /* 應警告 */
    printf("%d",b);
    return a + b + y;
}


