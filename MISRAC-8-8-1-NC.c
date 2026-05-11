/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

extern int internal_object;  /* Non-compliant */
static int internal_object = 1;

int main(void)
{
    return internal_object;
}

