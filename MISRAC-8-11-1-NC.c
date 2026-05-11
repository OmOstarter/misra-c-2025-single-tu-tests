/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

extern int external_array[]; /* Non-compliant*/
int external_array[4] = { 0, 1, 2, 3 };

int main(void)
{
    return external_array[0];
}

