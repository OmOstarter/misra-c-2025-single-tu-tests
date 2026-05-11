/* MISRA C:2025 Rule 8.1 - Non-compliant examples
 */

/* Non-compliant */
extern x;

/* Non-compliant */
const y = 5;

/* Non-compliant */
extern f(void);

/* Non-compliant */
struct str {
    int a;
    const b;
} s;

/* Non-compliant*/
void h(a)
{
    (void)a;
}

/* Non-compliant*/
g(void)
{
    return 0;
}

int main(void)
{
    (void)x;
    (void)y;
    (void)f;
    (void)s;
    h(1);
    (void)g();
    return 0;
}
