/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int main(void)
{
    char *p = "abc";              /* Non-compliant. */
    const char *q = "def";        /* Compliant. */
    return (int)p[0] + (int)q[0];
}

