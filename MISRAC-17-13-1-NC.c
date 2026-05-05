#include <stdint.h>

// 函數返回型別使用型別限定符
const uint16_t cf(void);       // 合規 - 返回 const uint16_t
const uint16_t *pcf(void);     // 合規 - 返回指向 const uint16_t 的指標

// 函數類型定義
typedef uint16_t ftype(void);  // 定義函數類型

// 指向函數的指標可以帶有型別限定符
typedef ftype *const pcftype;  // 合規 - 指向 ftype 的 const 指標

// 錯誤：函數類型本身被型別限定符修飾
typedef const ftype cftype;    // 不合規 - ftype 被 const 修飾
int main(){

}