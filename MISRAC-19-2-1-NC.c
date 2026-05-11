/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

union U                      /* Non-compliant */
{
    int i;
    float f;
};

int main(void)
{
    union U u = { 0 };
    return u.i;
}

