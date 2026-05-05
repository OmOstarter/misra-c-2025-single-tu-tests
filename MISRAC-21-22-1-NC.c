#include <tgmath.h>

void fn1(void) {
    float   f1, f2;
    int     i1, i2;
    char    c1, c2;
    void   *p1, *p2;

    f2 = sqrt(f1);    // 合規 - 基本實數浮點型別
    i2 = sqrt(i1);    // 合規 - 基本有號型別
    c2 = sqrt(c1);    // 不合規 - 基本字符型別（未定義行為）
    p2 = sqrt(p1);    // 不合規 - 指標型別（未定義行為）
}
