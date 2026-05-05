/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#define CONTROL_VALUE 1
#define CONTROL_VALUE 2     /* Non-compliant: macro identifier is not distinct. */

int main(void)
{
    return CONTROL_VALUE;
}

