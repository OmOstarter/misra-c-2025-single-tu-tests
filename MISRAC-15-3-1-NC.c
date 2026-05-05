/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int main(void)
{
    goto inner;              /* Non-compliant: target label is in nested block. */
    {
inner:
        return 0;
    }
}

