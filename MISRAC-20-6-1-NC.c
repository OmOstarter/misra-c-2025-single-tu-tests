/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.
 */

#include <stdio.h>

#define M(A) printf(#A)

int main(void)
{
    M(
#ifdef SW          /* Non-compliant */
    "Message 1"
#else              /* Non-compliant */
    "Message 2"
#endif             /* Non-compliant */
    );

    return 0;
}
