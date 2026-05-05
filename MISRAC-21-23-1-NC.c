#include <tgmath.h>

void f(void) {
    float   f1, f2;
    double  d1, d2;

    f2 = pow(f1, f2);            // 合規 - 參數型別一致，都是 float
    d2 = pow(d1, d2);            // 合規 - 參數型別一致，都是 double

    f2 = pow(f1, d2);            // 不合規 - 參數型別不一致，float 與 double
    f2 = pow(f1, (float)d2);     // 合規 - 明確轉型以確保參數型別一致
}

void g(void) {
    short s16;
    int   i32;
    long  l32;

    i32 = pow(s16, i32);         // 合規 - 參數經整數提升後，型別一致為 int
    i32 = pow(i32, l32);         // 不合規 - 提升後型別分別為 int 和 long

    i32 = pow(s16, 10);          // 合規 - 字面值 10 的型別為 int
    i32 = pow(10u, 110ul);       // 不合規 - 字面值型別分別為 unsigned int 和 unsigned long
}
