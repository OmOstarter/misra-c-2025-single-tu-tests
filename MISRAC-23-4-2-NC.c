/* file1.c — Example set 1: function/array vs pointers */
#include <stdint.h>
#include <stddef.h>

typedef int32_t Func (int);
typedef int32_t Array [10];
typedef Func  * FuncP;
typedef Array * ArrayP;

/* Dummies to keep linking clean */
int32_t handle_funcp (FuncP p) { (void)p; return 0; }
int32_t handle_intp  (int32_t *p) { (void)p; return 0; }

/* Non-compliant  */
#define handle_function_nc(X) _Generic((X)                    \
                              , Func : handle_funcp (&(X))    \
                              , FuncP: handle_funcp   (X)  )

/* Non-compliant  */
#define handle_array_nc(X) _Generic((X)                       \
                           , Array    : handle_intp ((X) + 0) \
                           , ArrayP   : handle_intp (*(X))    \
                           , int32_t *: handle_intp (X) )

/* Compliant */
#define handle_function(X) _Generic( (X), FuncP: handle_funcp (X) )

/* Compliant */
#define handle_array(X) _Generic(&(X)[0]                      \
                        , int32_t *: handle_intp (X)          \
                        , ArrayP   : handle_intp (*(X)) )

int main(void) {
    Array  arr1;
    Array  arr2[10];  /* Two-dimensional - array of arrays */
    FuncP  fp = 0;

    /*  合規示範（不會觸發 23.4） */
    handle_array (arr1); /* &(arr1[0]) → int32_t * */
    handle_array (arr2); /* &(arr2[0]) → ArrayP    */

    /*  不合規示範（會觸發 23.4） */
    (void)handle_array_nc(arr1);   /* 23.4：array type 被列在 association */
    (void)handle_function_nc(*fp); /* 23.4：function type 被列在 association */

    return 0;
}
