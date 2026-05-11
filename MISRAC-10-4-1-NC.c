/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#include <stdint.h>

int main(void)
{
    int32_t s = -1;
    uint32_t u = 1U;
    return (s < u) ? 1 : 0;  /* Non-compliant*/
}

