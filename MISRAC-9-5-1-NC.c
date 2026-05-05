/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int a[] = { [2] = 1 };       /* Non-compliant: designated array initializer without explicit size. */
int b[3] = { [2] = 1 };      /* Compliant. */

int main(void)
{
    return a[0] + b[0];
}

