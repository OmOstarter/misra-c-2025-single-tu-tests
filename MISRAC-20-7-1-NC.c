/* MISRA C:2025 Rule 20.7 - Non-compliant examples
 * Expressions resulting from macro parameter expansion shall be
 * appropriately delimited.
 *
 * Violations:
 *   1. #define M1(x, y) (x * y)  -- x and y lack surrounding delimiters
 *
 * Compliant:
 *   - #define M2(x, y) ((x) * (y))        -- each param parenthesized
 *   - #define GET_MEMBER(S, M) ((S)).M    -- S parenthesized, M is member name
 *   - #define F(X) G((X))                 -- X delimited by ( and )
 *   - #define CALL(A, I) f((I), (A)[(I)]) -- all params properly delimited
 */

#include <stdint.h>

/* Non-compliant: x and y are not surrounded by delimiters */
#define M1(x, y) (x * y)              /* Non-compliant */

/* Compliant: each parameter is individually parenthesized */
#define M2(x, y) ((x) * (y))          /* Compliant */

/* Compliant: S is parenthesized; M is a member name (after .), not an expression */
struct S { int16_t minval; };
#define GET_MEMBER(S_arg, M) ((S_arg)).M    /* Compliant */

/* Compliant: X is delimited by ( and ) in G(X) */
#define G(Y) ((Y) + 1)                /* Compliant */
#define F(X) G((X))                   /* Compliant */

/* Compliant: I delimited by ( and ,; A between , and [; second I between [ and ] */
#define CALL(A, I) f((I), (A)[(I)])   /* Compliant */

static int16_t f(int16_t a, int16_t b) { return (int16_t)((int16_t)a + b); }

int main(void)
{
    int16_t r;
    int16_t arr[4];
    struct S s1;
    arr[0] = 1; arr[1] = 2; arr[2] = 3; arr[3] = 4;
    s1.minval = 5;

    r = M1(1 + 2, 3 + 4);            /* Expands to (1 + 2 * 3 + 4) = 11 */
    r = M2(1 + 2, 3 + 4);            /* Expands to ((1+2)*(3+4)) = 21 */
    r = GET_MEMBER(s1, minval);
    r = F(2);
    r = CALL(arr, (int16_t)1);
    return (int)r;
}
