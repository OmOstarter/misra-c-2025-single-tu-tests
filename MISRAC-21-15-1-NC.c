/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#include <string.h>

int main(void)
{
    int src = 0;
    unsigned int dst = 0U;
    (void)memcpy(&dst, &src, sizeof(dst)); /* Non-compliant */
    return (int)dst;
}

