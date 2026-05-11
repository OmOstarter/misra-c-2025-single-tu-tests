/*
 * MISRA C:2025 Rule 20.3 test.
 * Compliant: macro expands to a proper <filename> or "filename" token.
 * Non-compliant: macro expands to bare tokens (no angle brackets or quotes).
 */

/* Compliant  */
#define HEADER <stdint.h>
#include HEADER

/* Non-compliant */
#define FILENAME stdint.h
#include FILENAME

int main(void) { return 0; }
