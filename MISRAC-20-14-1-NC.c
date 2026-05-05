/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#if 1
#include "MISRAC-20-14-1.h"  /* Header contains the matching #endif: non-compliant. */

int main(void)
{
    return 0;
}

