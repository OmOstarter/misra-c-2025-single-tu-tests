/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int main(void)
{
    int x = 0;
    void *vp = &x;
    int *ip = (int *)vp;     /* Non-compliant: void pointer to object pointer. */
    return *ip;
}

