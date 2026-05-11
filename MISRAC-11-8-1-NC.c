/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int main(void)
{
    const int x = 1;
    int *p = (int *)&x;      /* Non-compliant*/
    return *p;
}

