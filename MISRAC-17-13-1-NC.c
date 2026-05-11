#include <stdint.h>

// 函數返回型別使用型別限定符
const uint16_t cf(void);       // compliant
const uint16_t *pcf(void);     // compliant

// 函數類型定義
typedef uint16_t ftype(void);  // 定義函數類型

// 指向函數的指標可以帶有型別限定符
typedef ftype *const pcftype;  // compliant

// 錯誤：函數類型本身被型別限定符修飾
typedef const ftype cftype;    // non-compliant
int main(){

}