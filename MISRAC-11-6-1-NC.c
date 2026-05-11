/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#include <stdint.h>

int main(void)
{
    void *ptr = (void *)0x1234u;       /* Non-compliant*/
    void *fp = (void *)1024.0f;        /* Non-compliant*/
    uint32_t u = (uint32_t)ptr;        /* Non-compliant*/
    uintptr_t uip = (uintptr_t)ptr;    /* Compliant*/
    void *ok_ptr = (void *)uip;        /* Compliant */
    void *zero = (void *)0;            /* Compliant */

    (void)fp;
    (void)u;
    (void)ok_ptr;
    (void)zero;
    return ptr == 0 ? 0 : 1;
}
