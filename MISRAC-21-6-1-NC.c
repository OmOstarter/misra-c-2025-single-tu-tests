/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#include <stdio.h>

int main(void)
{
    printf("MISRA\n");       /* Non-compliant */
    return 0;
}

