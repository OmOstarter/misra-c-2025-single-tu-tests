/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#define LOCAL_MACRO 1
#undef LOCAL_MACRO           /* Non-compliant: undef used. */

int main(void)
{
    return 0;
}

