/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#if UNDEFINED_FLAG           /* Non-compliant */
#endif

int main(void)
{
    return 0;
}

