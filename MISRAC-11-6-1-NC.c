/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#include <stdint.h>

int main(void)
{
    void *ptr = (void *)0x1234u;       /* Non-compliant: integer to void pointer. */
    void *fp = (void *)1024.0f;        /* Non-compliant: floating to void pointer. */
    uint32_t u = (uint32_t)ptr;        /* Non-compliant: void pointer to integer. */
    uintptr_t uip = (uintptr_t)ptr;    /* Compliant: uintptr_t exception. */
    void *ok_ptr = (void *)uip;        /* Compliant: uintptr_t exception. */
    void *zero = (void *)0;            /* Compliant: integer constant zero. */

    (void)fp;
    (void)u;
    (void)ok_ptr;
    (void)zero;
    return ptr == 0 ? 0 : 1;
}
