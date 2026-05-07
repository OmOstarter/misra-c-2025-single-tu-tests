/* MISRA C:2025 Rule 20.1 - Non-compliant examples
 * Violations:
 *   1. #include <stddef.h> -- code (variable declaration) precedes it
 *
 * Compliant:
 *   - #include <stdint.h> -- only #define and comments precede it
 */

/* Compliant: only preprocessor directive and comments before this include */
#define MISRAC_20_1_MACRO 1
#include <stdint.h>   /* Compliant */

/* Non-compliant: code (variable declaration) now precedes subsequent include */
static uint16_t code_before_include = MISRAC_20_1_MACRO;  /* code, not a directive */
#include <stddef.h>                                         /* Non-compliant */

int main(void)
{
    return (int)(size_t)code_before_include;
}
