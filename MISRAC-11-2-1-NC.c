/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

struct Incomplete;

int main(void)
{
    struct Incomplete *p = 0;
    int *q = (int *)p;       /* Non-compliant*/
    return q == 0 ? 0 : 1;
}

