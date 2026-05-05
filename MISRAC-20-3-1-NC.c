/*
 * MISRA C:2025 Rule 20.3 test.
 * Rule: The #include directive shall be followed by either a
 * <filename> or "filename" sequence (checked after macro replacement).
 *
 * Compliant: macro expands to a proper <filename> or "filename" token.
 * Non-compliant: macro expands to bare tokens (no angle brackets or quotes).
 */

/* Compliant: HEADER expands to <stdint.h> — a proper <filename> form */
#define HEADER <stdint.h>
#include HEADER

/* Non-compliant: FILENAME expands to bare tokens stdint.h (no < > or " ") */
#define FILENAME stdint.h
#include FILENAME

int main(void) { return 0; }
