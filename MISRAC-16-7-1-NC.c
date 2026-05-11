/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#include <stdbool.h>

int main(void)
{
    bool b = true;
    switch (b)               /* Non-compliant */
    {
    case true:
        break;
    default:
        break;
    }
    return 0;
}

