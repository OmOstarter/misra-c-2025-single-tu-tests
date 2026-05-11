/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

static int f(int unused)   /* Non-compliant */
{
    return 0;
}

int main(void)
{
    return f(1);
}

