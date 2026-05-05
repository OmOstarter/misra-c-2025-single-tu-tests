#include <tgmath.h>
#include <complex.h>

void fn2(void) {
    float          f1, f2;
    _Complex float cf1, cf2;

    f2 = sqrt(f1);    // 合規 - 實數參數
    cf2 = sqrt(cf1);  // 合規 - `sqrt` 支援複數參數

    f2 = ceil(f1);    // 合規 - 實數參數
    cf2 = ceil(cf1);  // 不合規 - `ceil` 不支援複數參數（未定義行為）
}
//<tgmath.h> 中，ceil 既可以是函數，也可以是巨集，這取決於標頭檔案的使用和程式碼的具體上下文。
//如果包含的是 <math.h>，ceil 是標準函數。
//如果包含的是 <tgmath.h>，ceil 是型別通用巨集（type-generic macro）。
/*
它可以根據參數的型別自動調用對應的函數（例如 ceilf、ceil 或 ceill）。
巨集的實現會根據參數型別展開為正確的標準函數，例如：
若參數為 float，則展開為 ceilf。
若參數為 double，則展開為 ceil。
若參數為 long double，則展開為 ceill。
*/