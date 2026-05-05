/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#include <stdlib.h>

int main(void)
{
    void *p = malloc(16U);   /* Non-compliant: memory allocation function used. */
    free(p);                 /* Non-compliant: deallocation function used. */
    return 0;
}

