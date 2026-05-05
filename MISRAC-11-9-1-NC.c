/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#include <stddef.h>
#include <stdint.h>

static int32_t *g;

static void f(void)
{
    int32_t *p1 = 0;             /* Non-compliant: integer 0, not NULL */
    int32_t *p2 = (void *)0;     /* Compliant: (void*)0 form */
    int32_t *p3 = NULL;          /* Compliant: NULL macro */

    /* Comparison */
    if (p1 == 0) {}              /* Non-compliant */
    if (p2 == NULL) {}           /* Compliant */
    if (p3 != 0) {}              /* Non-compliant */

    /* Ternary: third operand is integer 0 */
    int32_t *p4 = (p1 != NULL) ? p1 : 0;    /* Non-compliant */
    int32_t *p5 = (p1 != NULL) ? p1 : NULL; /* Compliant */

    g = p4; (void)p5;
}

int main(void)
{
    f();
    return 0;
}
