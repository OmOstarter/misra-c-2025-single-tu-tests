/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

enum E
{
    E_A,
    E_B = 0,                /* Non-compliant: duplicates implicit E_A value. */
    E_C
};

int main(void)
{
    return E_C;
}

