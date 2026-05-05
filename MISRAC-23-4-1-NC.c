
#include <stdint.h>
#include <stddef.h>     /* size_t */
#include <stdatomic.h>  /* _Atomic */

/* ==== 被呼叫的處理函式（提供定義避免額外噪音） ==== */
typedef int32_t Func (int);
typedef int32_t Array[10];
typedef Func  * FuncP;
typedef Array * ArrayP;

int32_t handle_funcp (FuncP p)                 { (void)p; return 0; }
int32_t handle_intp  (int32_t *p)              { (void)p; return 0; }
/* 為了不觸發 discarded-qualifiers，把參數做最寬鬆：const volatile void* */
int32_t handle_other_value (const volatile void *p){ (void)p; return 0; }
int32_t handle_sized_string (size_t n, const char *s){ (void)n; (void)s; return 0; }
int32_t handle_null_terminator (int n, const char *s){ (void)n; (void)s; return 0; }

/* ==== 方便測試的 typedef ==== */
typedef int32_t        Int;
typedef const int32_t  CInt;   /* 頂層 const 物件型別（不該列） */
typedef volatile int32_t VInt; /* 頂層 volatile 物件型別（不該列） */
typedef _Atomic(int32_t) AInt; /* 頂層 atomic 物件型別（不該列） */

/* ==== 降噪小巨集：只在型別吻合時才讓右式被型別檢查 ==== */
#define WHEN_COMPAT(X, T, EXPR) \
  __builtin_choose_expr(__builtin_types_compatible_p(__typeof__(X), T), (EXPR), (void)0)

/* ==== 23.4 不符合示範：列出「不可被選到」的型別 ==== */

/* 函式型別（FUNCTION_TYPE）不該列；GCC 也會內建報錯 */
#define handle_function_nc(X) _Generic((X),                                   \
  Func  : WHEN_COMPAT((X), Func,  handle_funcp (&(X))),                       \
  FuncP : WHEN_COMPAT((X), FuncP, handle_funcp (X))                           \
)

/* 陣列型別（ARRAY_TYPE）不該列；用 WHEN_COMPAT 壓掉無關分支的型別檢查 */
#define handle_array_nc(X) _Generic((X),                                      \
  Array     : WHEN_COMPAT((X), Array,     handle_intp ((X) + 0)),             \
  ArrayP    : WHEN_COMPAT((X), ArrayP,    handle_intp (*(X))),                \
  int32_t * : WHEN_COMPAT((X), int32_t *, handle_intp (X))                    \
)

/* 頂層 const 物件型別不該列 */
#define filter_const_nc(X) ( _Generic((X),                                    \
  CInt   : WHEN_COMPAT((X), CInt,   handle_other_value (&(X))),               \
  default:                               handle_other_value (&(X)) ) )

/* 頂層 volatile 物件型別不該列 */
#define filter_volatile_nc(X) ( _Generic((X),                                 \
  VInt   : WHEN_COMPAT((X), VInt,   handle_other_value (&(X))),               \
  default:                               handle_other_value (&(X)) ) )

/* 頂層 _Atomic 物件型別不該列 */
#define filter_atomic_nc(X) ( _Generic((X),                                   \
  AInt   : WHEN_COMPAT((X), AInt,   handle_other_value (&(X))),               \
  default:                               handle_other_value (&(X)) ) )

/* 未命名 struct/union（每次出現皆為新型別）不該列 */
#define filter_unnamed_struct_nc(X) _Generic((X),                              \
  struct { int a; } : handle_other_value (&(X)),                               \
  default          : handle_other_value (&(X)) )

/* ==== 23.4 合規示範：只列「可被選到」的型別 ==== */

/* 只列函式指標（可被選到），不列函式本體型別 */
#define handle_function(X) _Generic((X), FuncP: handle_funcp (X))

/* 用 &(X)[0] 讓控制運算元成為指標，匹配元素指標或「指向陣列的指標」 */
#define handle_array(X) _Generic(&(X)[0],                                      \
  int32_t *: handle_intp (X),                                                  \
  ArrayP   : handle_intp (*(X)) )

/* 注意：指到目標的限定詞保留，因此可以同時列 CInt* 和 Int* */
#define filter_const(X) ( _Generic((X),                                        \
  CInt * : handle_other_value (X),                                             \
  Int  * : handle_other_value (X),                                             \
  default:  handle_other_value (X) ) )

/* 陣列尺寸相關：不列陣列型別，改列「指向陣列的指標」 */
#define SizeofNonEmpty(A) (sizeof (A) > 1 ? sizeof (A) : 2)
#define only_strings_nc(X) _Generic((X),                                       \
  char[SizeofNonEmpty (X)]: handle_sized_string (sizeof (X), (X)),             \
  char[1]                 : handle_null_terminator (1, (X)) )

#define only_strings(X) _Generic(&(X),                                         \
  char (*) [SizeofNonEmpty (X)]: handle_sized_string (sizeof (X), (X)),        \
  char (*) [1]                : handle_null_terminator (1, (X)) )

int main(void)
{
  Array  arr1;
  Array  arr2[10];
  FuncP  fp = 0;
  Int    i = 0;
  const Int ci = 0;
  volatile Int vi = 0;
  AInt   ai = 0;

  /* === 不符合：應觸發 MISRA 23.4 警告（加上一條 GCC 內建 function-type error） === */
  (void)handle_function_nc (*fp);   /* 列了函式型別 */
  (void)handle_array_nc(arr1);      /* 列了陣列型別 */
  (void)filter_const_nc(ci);        /* 列了頂層 const 物件型別 */
  (void)filter_volatile_nc(vi);     /* 列了頂層 volatile 物件型別 */
  (void)filter_atomic_nc(ai);       /* 列了頂層 _Atomic 物件型別 */
  (void)filter_unnamed_struct_nc(i);/* 列了未命名 struct 型別 */

  /* === 合規：不應觸發 23.4 === */
  (void)handle_function(fp);
  (void)handle_array(arr1);
  (void)filter_const(&ci);

  /* 尺寸相依的兩組：一組不合規（列陣列），一組合規（列指向陣列的指標） */
  only_strings_nc("hello");   /* 不合規：列了 array 型別（會有 23.4 警告＋選不到的錯） */
  only_strings("world");      /* 合規：匹配為 char (*)[6] */

  (void)sizeof arr2;          /* 讓編譯器確實看見二維陣列型別一次 */

  return 0;
}
