/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

struct S
{
    signed int bad : 1;     /* Non-compliant: named single-bit signed bit-field. */
    unsigned int ok : 1;
};

int main(void)
{
    return 0;
}

