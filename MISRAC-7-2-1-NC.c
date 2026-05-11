/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#include <stdint.h>

#if 0x8000000000000000
static uint64_t pp_bad = 0U;          /* Non-compliant*/
#endif

int main(void)
{
    uint64_t a = 0x8000000000000000;   /* Non-compliant*/
    uint64_t b = 0x8000000000000000U;  /* Compliant. */
    return (int)(a + b);
}
