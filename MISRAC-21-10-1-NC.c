/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#include <time.h>

int main(void)
{
    time_t now = time(0);    /* Non-compliant: time/date function used. */
    return (int)now;
}

