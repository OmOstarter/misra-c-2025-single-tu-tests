/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#define MAKE_NAME(a, b) a ## b   /* Non-compliant */

int main(void)
{
    int MAKE_NAME(local, value) = 0;
    return localvalue;
}

