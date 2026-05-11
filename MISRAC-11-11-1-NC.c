/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

static uint32_t val;

static void f(uint32_t *ptr)
{
    /* Assignment / if-statement */
    if (ptr != NULL) {}          /* Compliant */
    if (ptr != 0) {}             /* Compliant */
    if (ptr) {}                  /* Non-compliant */
    /* Logical NOT */
    if (!ptr) {}                 /* Non-compliant */

    /* Logical AND / OR */
    if (ptr && val == 1u) {}     /* Non-compliant */
    if (ptr == NULL || val > 0u) {} /* Compliant */

    /* Ternary first operand */
    val = ptr ? 1u : 0u;         /* Non-compliant */
    val = (ptr != NULL) ? 1u : 0u; /* Compliant */

    /* while / do-while / for */
    while (ptr) { break; }       /* Non-compliant */
    do { break; } while (ptr);   /* Non-compliant */
    for (; ptr; ) { break; }     /* Non-compliant */
}

int main(void) { f(NULL); return 0; }
