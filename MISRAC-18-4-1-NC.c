/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int main(void)
{
    int a[4] = { 0 };
    int *p = &a[0];
    p = p + 1;               /* Non-compliant: pointer arithmetic. */
    return *p;
}

