/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#include <stdlib.h>

static int cmp(const void *a, const void *b)
{
    return (*(const int *)a - *(const int *)b);
}

int main(void)
{
    int a[2] = { 2, 1 };
    qsort(a, 2U, sizeof(a[0]), cmp); /* Non-compliant. */
    return a[0];
}

