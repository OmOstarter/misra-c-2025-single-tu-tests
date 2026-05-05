/* MISRA C:2025 Rule 5.10 - Non-compliant examples
 * A reserved identifier or reserved macro name shall not be declared.
 *
 * Violations:
 *   1. Macro name begins with '_'            (_MY_CONSTANT)
 *   2. File-scope variable begins with '_'   (_global_count)
 *   3. Function name begins with '_'         (_BUILTIN_sqrt)
 *   4. Standard library function redeclared  (memcpy)
 *   5. Local variable begins with '_'        (_local_var)
 */

#include <stddef.h>

/* Non-compliant: macro name begins with '_' */
#define _MY_CONSTANT 42

/* Non-compliant: file-scope identifier begins with '_' */
static int _global_count = 0;

/* Non-compliant: function name begins with '_' */
static double _BUILTIN_sqrt(double x)
{
    return x * x;
}

/* Non-compliant: explicit redeclaration of standard library function */
extern void *memcpy(void *restrict s1, const void *restrict s2, size_t n);

int main(void)
{
    /* Non-compliant: local identifier begins with '_' */
    int _local_var = _MY_CONSTANT;
    _global_count += (int)_BUILTIN_sqrt((double)_local_var);
    return _global_count;
}
