/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#define CALL(x) x

int main(void)
{
    CALL(#include <stdint.h>) /* Non-compliant: directive-like tokens in macro argument. */
    return 0;
}

