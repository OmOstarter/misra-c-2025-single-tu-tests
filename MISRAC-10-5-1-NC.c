/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#include <stdbool.h>

int main(void)
{
    bool b = (bool)3;        /* Non-compliant: cast to essentially Boolean from integer. */
    return b ? 0 : 1;
}

