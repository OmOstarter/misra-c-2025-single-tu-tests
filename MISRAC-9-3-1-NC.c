/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int main(void)
{
    int x[3] = { 0, 1, 2 };                  /* Compliant */
    int y[3] = { 0, 1 };                     /* Non-compliant */
    float t[4] = { [1] = 1.0f, 2.0f };       /* Non-compliant */
    float z[50] = { [1] = 1.0f, [25] = 2.0f }; /* Compliant:*/
    float arr[3][2] = {
        { 0.0f, 0.0f },
        { 0.25f, -0.25f },
        { 0 }                               /* Compliant by {0} exception. */
    };
    float array[5] = { 0 };                  /* Compliant by {0} exception. */
    char h[10] = "Hello";                    /* Compliant */
    int m[2][2] = { { 1 }, { 2, 3 } };       /* Non-compliant */

    return x[0] + y[0] + (int)t[1] + (int)z[1] + (int)arr[0][0]
           + (int)array[0] + h[0] + m[0][0];
}
