/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int f();                    /* Non-compliant */

int f(a)
int a;                      /* Non-compliant*/
{
    return a;
}

int main(void)
{
    return f(1);
}

