/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int main(void)
{
    int i;
    for (i = 0; i < 10; ++i)
    {
        if (i == 2) { break; }
        if (i == 4) { break; } /* Non-compliant */

    }
    return i;
}

