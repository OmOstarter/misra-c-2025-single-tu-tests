/* MISRA C:2025 Rule 8.18 - Non-compliant examples
 * Violations are in MISRAC-8-18-1.h (included below):
 *   1. int32_t i;        -- tentative definition in header
 *   2. static int32_t k; -- static tentative definition in header
 *
 * Compliant declarations in this .c file:
 *   int32_t i;        -- tentative definition in .c file (OK)
 *   int32_t j = 0;    -- defining declaration (OK)
 */

#include "MISRAC-8-18-1.h"

/* Compliant: tentative definition in .c file, not in header */
int32_t i;

/* Compliant: defining declaration */
int32_t j = 0;

int main(void)
{
    return (int)(i + j + k);
}
