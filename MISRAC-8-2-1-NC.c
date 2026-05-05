/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int f();                    /* Non-compliant: not prototype form. */

int f(a)
int a;                      /* Non-compliant: old-style definition. */
{
    return a;
}

int main(void)
{
    return f(1);
}

