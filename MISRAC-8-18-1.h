/* MISRA C:2025 Rule 8.18 - Non-compliant header
 * There shall be no tentative definitions in a header file.
 *
 * Violations (tentative definitions at file scope, no initializer, no extern):
 */

#include <stdint.h>

int32_t i;          /* Non-compliant */
static int32_t k;   /* Non-compliant */

/* Compliant*/
extern int32_t j;
