/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int main(void)
{
    int x = 0;
    const char *date_format = "??-??-??"; /* Non-compliant: trigraphs in a string literal. */
    /* Non-compliant: trigraph in a comment: ??) */
    ??=define LOCAL_VALUE 1  /* Non-compliant: trigraph used for '#'. */
#ifndef LOCAL_VALUE
#define LOCAL_VALUE 0
#endif
    (void)date_format;
    return x + LOCAL_VALUE;
}
