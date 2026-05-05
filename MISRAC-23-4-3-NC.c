/* file2.c — Example set 2: top-level qualifiers vs pointed-to qualifiers */
#include <stdint.h>
#include <stddef.h>

typedef int32_t Int;
typedef int32_t const CInt;

/* Dummies to keep linking clean */
int32_t handle_const_intp (const int32_t *p) { (void)p; return 0; }
int32_t handle_other_value (void) { return 0; }

/* Non-compliant */
#define filter_const_nc(X) ( _Generic((X)                           \
                           , CInt   : handle_const_intp             \
                           , default: handle_other_value ) (&(X)) )

/* Compliant */
#define filter_const(X) ( _Generic((X)  \
                        , CInt * : handle_const_intp                \
                        , Int *  : handle_const_intp                \
                        , default: handle_other_value ) (X) )

int main(void) {
    Int i = 0;
    CInt ci = 0;

    /* Exercise both macros */
    (void)filter_const_nc(ci);   /* Non-compliant: object-level qualifier is not selectable */
    (void)filter_const(&ci);     /* Compliant: qualifier on pointed-to type */
    (void)filter_const(&i);      /* Compliant: plain Int* */
    return 0;
}
