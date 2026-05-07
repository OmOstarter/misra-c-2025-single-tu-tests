/* rule23_7_clean.c
 *
 * 純粹用來測 MISRA-C Rule 23.7：
 */

#include <stdint.h>

typedef float       float32_t;
typedef double      float64_t;
typedef long double float128_t;

/* 假函式，內容不重要，只是讓程式可編譯 */
static void fun1f (float32_t x)   { (void)x; }
static void fun1  (float64_t x)   { (void)x; }
static void fun1l (long double x) { (void)x; }

static void fun2f (float32_t x)   { (void)x; }
static void fun2  (float64_t x)   { (void)x; }
static void fun2l (long double x) { (void)x; }

static void fun3f (float32_t x)   { (void)x; }
static void fun3  (float64_t x)   { (void)x; }
static void fun3l (long double x) { (void)x; }

static int default_result = 0;

/* === 合規範例 1：外面才呼叫 (X) === */
/* 預期：不違反 23.7 */
#define gfun1(X) ( _Generic((X)             \
                 , float32_t: fun1f         \
                 , float64_t: fun1          \
                 , default  : fun1l) (X) )

/* === 合規範例 2：每個 association 都用到 X === */
/* 預期：不違反 23.7 */
#define gfun2(X)   _Generic((X)             \
                 , float32_t: fun2f (X)     \
                 , float64_t: fun2  (X)     \
                 , default  : fun2l (X) )

/* === 非合規範例：default 沒有評估 X === */
/* 預期：違反 23.7 */
#define gfun3(X)   _Generic((X)                 \
                 , float32_t : fun3f (X)        \
                 , float64_t : fun3  (X)        \
                 , float128_t: fun3l (X)        \
                 , default   : default_result )

/* === 自訂再加一個違規範例：不是只有 default 也會出問題 === */
/* 預期：違反 23.7
 * - int   association: 用到 X
 * - float association: 不用 X
 * - default association: 用到 X
 */
#define gfun4(X)   _Generic((X)                \
                 , int   : (X) + 1             \
                 , float : 0.0f               /* 不用 X */ \
                 , default: (X) - 1 )

int main (void)
{
  float32_t  f32  = 1.0f;
  float64_t  f64  = 2.0;
  float128_t f128 = 3.0L;  /* 只是避免未使用警告 */
  int        i    = 0;

  (void)f128;  /* 壓掉未使用警告 */

  /* ─── 合規情況 ─── */

  /* 預期：不違反 23.7 */
  gfun1(f32);

  /* 預期：不違反 23.7 */
  gfun2(f64);

  /* ─── 違反 23.7 的情況 ─── */

  /* 預期：違反 23.7
   * 某些 association 用 X（fun3f/fun3/fun3l），
   * default 完全不用 X（default_result）
   */
  gfun3(i++);   /* ★ 這裡應該出 23.7 警告 */

  /* 形式上仍違反 23.7：default 那一條也沒用到 X */
  gfun3(f32++); /* ★ 理論上會被「混用」條件抓到 */

  /* 預期：違反 23.7
   * gfun4(int):
   *   - int   : (X) + 1     → 用 X
   *   - float : 0.0f        → 不用 X
   *   - default: (X) - 1    → 用 X
   */
  gfun4(i++);   /* ★ 這裡也應出 23.7 警告 */

  return 0;
}
