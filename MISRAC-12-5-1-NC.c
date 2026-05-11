/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#include <stddef.h>

void f(int a[10])
{
    (void)sizeof(a);        /* Non-compliant */

}

int main(void)
{
    int a[10] = { 0 };
    f(a);
    return 0;
}

