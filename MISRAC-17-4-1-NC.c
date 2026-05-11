/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int f(int x)
{
    if (x > 0)
    {
        return 1;
    }
                            /* Non-compliant */
}

int main(void)
{
    return f(0);
}

