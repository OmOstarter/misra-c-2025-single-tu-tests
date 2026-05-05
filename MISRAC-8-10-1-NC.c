/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

inline int add_one(int x)    /* Non-compliant: inline function is not static. */
{
    return x + 1;
}

int main(void)
{
    return add_one(1);
}

