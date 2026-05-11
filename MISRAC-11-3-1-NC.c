/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int main(void)
{
    int x = 0;
    unsigned int *p = (unsigned int *)&x; /* Non-compliant*/
    char *bytes = (char *)&x;             /* Compliant*/
    const short *sp = (const short *)&x;  /* Non-compliant*/
    const volatile short *q = sp;         /* Compliant*/
    int *ip = &x;
    unsigned int *implicit = ip;          /* Non-compliant*/
    int * const *pcpi = &ip;
    const int * const *pcpci = (const int * const *)pcpi; /* Non-compliant*/

    (void)bytes;
    (void)q;
    (void)implicit;
    (void)pcpci;
    return (int)*p;
}
