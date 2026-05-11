/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

static int hidden = 0;

int main(void)
{
    int hidden = 1;         /* Non-compliant */
    return hidden;
}

