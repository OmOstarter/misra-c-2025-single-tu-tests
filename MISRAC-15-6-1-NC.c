/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int main(void)
{
    int x = 0;
    if (x == 0)
        x = 1;               /* Non-compliant: selection body is not compound. */
    return x;
}

