/* MISRA C:2025 Rule 4.1 - Non-compliant and compliant examples
 * Non-compliant: escape sequence followed by a character that is neither
 *   another escape sequence nor the end of the string/character constant.
 *
 * Compliant: escape sequence terminated by end of literal or by another
 *   escape sequence.
 */

#include <stdint.h>

/* Compliant*/
static const char s2[] = "\x41" "g";  /* Compliant */

/* Compliant */
static const char s3[] = "\x41\x67";  /* Compliant */

/* Non-compliant */
static const char s1[] = "\x41g";     /* Non-compliant */

/* Compliant: */
static const int c2 = '\141\t';       /* Compliant */

/* Non-compliant: */
static const int c1 = '\141t';        /* Non-compliant */

int main(void)
{
    return (int)s1[0] + (int)s2[0] + (int)s3[0] + c1 + c2;
}

