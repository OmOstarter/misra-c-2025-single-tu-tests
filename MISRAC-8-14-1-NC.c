/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

void f(int * restrict p)     /* Non-compliant*/
{
    *p = 1;
}

int main(void)
{
    int x = 0;
    f(&x);
    return x;
}

