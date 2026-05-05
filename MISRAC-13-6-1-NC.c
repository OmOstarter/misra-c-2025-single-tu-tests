/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#include <stddef.h>

int main(void)
{
    int x = 0;
    size_t s = sizeof(x++);  /* Non-compliant: side effect in sizeof operand. */
    return (int)s;
}

