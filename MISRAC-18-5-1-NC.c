/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int main(void)
{
    int x = 0;
    int *p = &x;
    int **pp = &p;
    int ***ppp = &pp;        /* Non-compliant: more than two pointer nesting levels. */
    return ***ppp;
}

