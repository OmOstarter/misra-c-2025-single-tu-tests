/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int main(void)
{
    int x = 1 + 2 * 3;       /* Non-compliant: precedence not explicit. */
    int y = 1 + (2 * 3);     /* Compliant. */
    return x + y;
}

