/* file3.c — Example set 3: trying to match array types vs pointer-to-array */
#include <stdint.h>
#include <stddef.h>

int32_t handle_sized_string (size_t n, const char *s) { (void)n; (void)s; return 0; }
int32_t handle_null_terminator (int n, const char *s) { (void)n; (void)s; return 0; }

/* Avoid multiple associations if size == 1 */
#define SizeofNonEmpty(A) (sizeof (A) > 1 ? sizeof (A) : 2)

/* Non-compliant  */
#define only_strings_nc(X) _Generic((X)                              \
  , char[SizeofNonEmpty (X)]: handle_sized_string (sizeof (X), (X))  \
  , char[1]                 : handle_null_terminator (1, (X)))

/* Compliant  */
#define only_strings(X) _Generic(&(X)                                     \
  , char (*) [SizeofNonEmpty (X)]: handle_sized_string (sizeof (X), (X))  \
  , char (*) [1]: handle_null_terminator (1, (X)))

int main(void) {
    only_strings_nc ("hello"); /* Constraint violation     */
    only_strings    ("world"); /* Matches as char (*) [6]  */
    return 0;
}
