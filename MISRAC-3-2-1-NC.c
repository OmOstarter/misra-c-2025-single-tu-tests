/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int main(void)
{
    // Non-compliant: line splicing inside a // comment \
    int x = 0;
    return 0;
}
