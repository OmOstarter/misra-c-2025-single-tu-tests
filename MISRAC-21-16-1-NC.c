/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#include <string.h>

struct S { int x; };

int main(void)
{
    struct S a = { 0 };
    struct S b = { 1 };
    return memcmp(&a, &b, sizeof(a)); /* Non-compliant: memcmp on struct object. */
}

