/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#include <stdint.h>

int main(void)
{
    int x = 0;
    uintptr_t address = (uintptr_t)&x;    /* Non-compliant*/
    return (int)address;
}

