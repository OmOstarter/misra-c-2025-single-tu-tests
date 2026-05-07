/* MISRA C:2025 Rule 20.12 - Non-compliant and compliant examples
 * Non-compliant:
 *   BB(AA) -- x used as both ## operand and regular expansion;
 *             AA is a macro so the two uses behave differently.
 *
 * Compliant:
 *   SCALE(speed) -- X has mixed use, but speed is not a macro.
 *   STRINGIFY(AA) -- x used only as # operand, no mixed use.
 *   CONCAT(a, b)  -- parameters used only as ## operands, no mixed use.
 */

#include <stdint.h>

/* Non-compliant macro: x used as ## operand AND as regular expansion */
#define AA        ((int32_t)0xffff)
#define BB(x)     ((x) + wow##x)     /* Non-compliant definition */

/* Compliant: X has mixed use but called with non-macro identifier */
int32_t speed;
int32_t speed_scale;
int32_t scaled_speed;
#define SCALE(X)  ((X) * X##_scale)  /* Compliant when called with non-macro */

/* Compliant: parameters used only as ## operands - no mixed use */
#define CONCAT(a, b) (a##b)

/* Compliant: parameter used only as # operand - no mixed use */
#define STRINGIFY(x) #x

int main(void)
{
    int32_t wowAA = (int32_t)0;

    /* Non-compliant: AA is a macro and x has mixed #/## + regular use */
    wowAA = BB(AA);              /* Non-compliant */

    /* Compliant: speed is not a macro */
    scaled_speed = SCALE(speed); /* Compliant */

    /* Compliant: no mixed use in STRINGIFY or CONCAT */
    (void)STRINGIFY(AA);         /* Compliant */

    return (int)wowAA;
}
