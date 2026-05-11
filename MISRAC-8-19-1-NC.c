/* MISRA C:2025 Rule 8.19 - Non-compliant examples
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

/* Non-compliant*/
extern int32_t i;

/* Compliant*/
int32_t i = 0;

void uses_externs(void)
{
    /* Non-compliant*/
    extern bool flag;

    /* Non-compliant*/
    extern void worker(bool f);

    worker(flag);
}

int main(void)
{
    uses_externs();
    return (int)i;
}
