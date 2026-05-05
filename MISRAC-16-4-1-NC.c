/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int main(void)
{
    int x = 0;
    switch (x)
    {
    case 0:
        break;               /* Non-compliant: no default label. */
    }
    return x;
}

