/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

struct Pair { int x; int y; };

int main(void)
{
    struct Pair a[2] = { 1, 2, 3, 4 };       /* Non-compliant*/
    struct Pair b[2] = { { 1, 2 }, { 3, 4 } }; /* Compliant. */
    return a[0].x + b[0].x;
}

