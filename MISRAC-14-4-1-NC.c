/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int main(void)
{
    int x = 1;
    if (x)                   /* Non-compliant */

    {
        return 1;
    }
    return 0;
}

