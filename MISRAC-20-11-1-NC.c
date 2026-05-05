/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#define BAD(a, b) #a ## b    /* Non-compliant: parameter after # followed by ##. */

int main(void)
{
    return 0;
}

