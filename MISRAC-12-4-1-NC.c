/*
 * MISRA C:2025 Rule 12.4 test.
 * Note: uint8_t/uint16_t operands are promoted to int before arithmetic,
 * so wrap-around only occurs when the operation type is unsigned int or wider.
 */

#include <stdint.h>

/* Compliant */
static const unsigned int ok1 = 1U + 1U;    /* = 2 */
static const unsigned int ok2 = 5U - 3U;    /* = 2 */
static const unsigned int ok3 = 2U * 3U;    /* = 6 */

/* Non-compliant */
static const unsigned int bad1 = 0U - 1U;           /* wraps to UINT_MAX */
static const unsigned int bad2 = 0xFFFFFFFFU + 1U;  /* wraps to 0 */
static const unsigned int bad3 = 0xFFFFFFFFU * 2U;  /* wraps */
