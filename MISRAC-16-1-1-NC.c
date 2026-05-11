/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int main(void)
{
    int x = 0;
    switch (x)               /* Non-compliant */

    {
    case 0:
        x = 1;
    case 1:
        x = 2;
    }
    return x;
}

