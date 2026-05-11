/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int main(void)
{
    int mode = 012;         /* Non-compliant*/
    int decimal = 10;       /* Compliant. */
    return mode + decimal;
}

