/* MISRA C:2025 Rule 8.19 - Non-compliant examples
 * There should be no external declarations in a source file.
 *
 * Violations:
 *   1. extern int32_t i;          -- extern var at file scope in .c
 *   2. extern bool flag;          -- extern var at block scope
 *   3. extern void worker(bool);  -- extern function at block scope
 *
 * Compliant (via header include):
 *   - extern int32_t i and extern void worker declared in MISRAC-8-19-1.h
 */

#include <stdint.h>
#include <stdbool.h>

/* Non-compliant: external declaration at file scope in a source file */
extern int32_t i;

/* Compliant: defining declaration in source file */
int32_t i = 0;

void uses_externs(void)
{
    /* Non-compliant: extern var at block scope */
    extern bool flag;

    /* Non-compliant: extern function at block scope */
    extern void worker(bool f);

    worker(flag);
}

int main(void)
{
    uses_externs();
    return (int)i;
}
