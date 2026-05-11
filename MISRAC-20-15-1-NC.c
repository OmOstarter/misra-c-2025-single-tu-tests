/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#define _Reserved_macro 1    /* Non-compliant */
#undef _Reserved_macro       /* Non-compliant  */

int main(void)
{
    return 0;
}

