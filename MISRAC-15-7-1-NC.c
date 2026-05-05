/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int main(void)
{
    int x = 0;
    if (x == 0)
    {
        x = 1;
    }
    else if (x == 1)
    {
        x = 2;               /* Non-compliant: else-if chain lacks final else. */
    }
    return x;
}

