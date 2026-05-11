/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

void f(int n)
{
    int a[n];                /* Non-compliant */
    a[0] = 0;
}

int main(void)
{
    f(4);
    return 0;
}

