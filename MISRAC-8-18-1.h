/* MISRA C:2025 Rule 8.18 - Non-compliant header
 * There shall be no tentative definitions in a header file.
 *
 * Violations (tentative definitions at file scope, no initializer, no extern):
 */

#include <stdint.h>

int32_t i;          /* Non-compliant: tentative definition in header */
static int32_t k;   /* Non-compliant: static tentative definition in header */

/* Compliant: external declaration only, no storage reserved */
extern int32_t j;
