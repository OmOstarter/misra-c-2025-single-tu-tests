/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int main(void)
{
    int x = 0;
    int flag = 1;
    switch (x)
    {
    case 1:
        if (flag)
        {
    case 2:                  /* Non-compliant */

            x = 1;
        }
        break;
    default:
        break;
    }
    return x;
}
