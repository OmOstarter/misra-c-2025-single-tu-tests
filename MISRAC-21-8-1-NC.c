/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#include <stdlib.h>

int main(void)
{
    exit(0);                 /* Non-compliant: termination function used. */
}

