/* MISRAC-8-19-1.h - Compliant header for Rule 8.19 test
 * External declarations belong here, in a header file.
 */

#include <stdint.h>
#include <stdbool.h>

extern int32_t i;        /* Compliant: external declaration in a header file */
extern void worker(bool flag);  /* Compliant: function declaration in header  */
