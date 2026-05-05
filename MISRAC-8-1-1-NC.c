/* MISRA C:2025 Rule 8.1 - Non-compliant examples
 * Types shall be explicitly specified.
 *
 * Violations:
 *   1. Object declaration with implicit int        (extern x)
 *   2. Qualified object with implicit int          (const y)
 *   3. Function declaration with implicit int ret  (extern f)
 *   4. Struct member with implicit int             (struct str.b)
 *   5. K&R-style parameter with implicit int       (void h(a))
 *   6. Function definition with implicit int ret   (g(void))
 */

/* Non-compliant: implicit int for external object */
extern x;

/* Non-compliant: implicit int for qualified object */
const y = 5;

/* Non-compliant: implicit int return type (function declaration) */
extern f(void);

/* Non-compliant: implicit int for struct member */
struct str {
    int a;
    const b;
} s;

/* Non-compliant: K&R-style parameter with implicit int */
void h(a)
{
    (void)a;
}

/* Non-compliant: function definition with implicit int return type */
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
