/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int main(void)
{
    long a = 10l;           /* Non-compliant: lowercase l suffix. */
    long b = 10L;           /* Compliant. */
    return (int)(a + b);
}

