/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int main(void)
{
    int x = 0;
    unsigned int *p = (unsigned int *)&x; /* Non-compliant: different object pointer type. */
    char *bytes = (char *)&x;             /* Compliant: character pointer exception. */
    const short *sp = (const short *)&x;  /* Non-compliant: different object pointer type. */
    const volatile short *q = sp;         /* Compliant: only qualifiers are added. */
    int *ip = &x;
    unsigned int *implicit = ip;          /* Non-compliant: implicit different object pointer type. */
    int * const *pcpi = &ip;
    const int * const *pcpci = (const int * const *)pcpi; /* Non-compliant: nested pointed-to type differs. */

    (void)bytes;
    (void)q;
    (void)implicit;
    (void)pcpci;
    return (int)*p;
}
