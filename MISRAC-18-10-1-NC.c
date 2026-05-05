#include <stdint.h>

/* Non-compliant：指向 VLA 的指標參數 */
void f1 (uint16_t n, uint16_t (*a)[n])   /* 這裡應警告 */
{
    uint16_t (*p)[20];  /* 固定長度，非 VLA —— 不警告 */
    (void)p;
}

/* Compliant：陣列參數會衰變為元素指標，非「指向陣列」 */
void f2 (uint16_t n, uint16_t a[n])      /* 不警告 */
{
    uint16_t *p = a;                      /* 不警告 */
    (void)p;
}

/* Non-compliant：多維 VLA 指標 */
void g (uint16_t m, uint16_t n, uint16_t (*a)[m][n])  /* 應警告 */
{
    (void)a;
}

/* Non-compliant：typedef 包住 pointer-to-VLA */
void h (uint16_t n)
{
    typedef uint16_t (*A)[n];
    A p;                                  /* 應警告 */
    (void)p;
}
int main(){
    
}