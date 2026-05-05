/* MISRA C:2025 Rule 4.1 - Non-compliant and compliant examples
 * Octal and hexadecimal escape sequences shall be terminated.
 *
 * Non-compliant: escape sequence followed by a character that is neither
 *   another escape sequence nor the end of the string/character constant.
 *
 * Compliant: escape sequence terminated by end of literal or by another
 *   escape sequence.
 */

#include <stdint.h>

/* Compliant: \x41 terminated by end of string literal */
static const char s2[] = "\x41" "g";  /* Compliant */

/* Compliant: \x41 terminated by another escape sequence */
static const char s3[] = "\x41\x67";  /* Compliant */

/* Non-compliant: \x41 followed by 'g' (not another escape, not end of literal) */
static const char s1[] = "\x41g";     /* Non-compliant */

/* Compliant: \141 terminated by another escape sequence */
static const int c2 = '\141\t';       /* Compliant */

/* Non-compliant: \141 followed by 't' (not another escape, not end of literal) */
static const int c1 = '\141t';        /* Non-compliant */

int main(void)
{
    return (int)s1[0] + (int)s2[0] + (int)s3[0] + c1 + c2;
}

