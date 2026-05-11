#include <stdint.h>

/* Non-compliant */
void f1 (uint16_t n, uint16_t (*a)[n])   /* 這裡應警告 */
{
    uint16_t (*p)[20];  /* 固定長度，非 VLA —— 不警告 */
    (void)p;
}

/* Compliant */
void f2 (uint16_t n, uint16_t a[n])      /* 不警告 */
{
    uint16_t *p = a;                      /* 不警告 */
    (void)p;
}

/* Non-compliant  */
void g (uint16_t m, uint16_t n, uint16_t (*a)[m][n])  /* 應警告 */
{
    (void)a;
}

/* Non-compliant  */
void h (uint16_t n)
{
    typedef uint16_t (*A)[n];
    A p;                                  /* 應警告 */
    (void)p;
}
int main(){
    
}