/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

int main(void)
{
    uint16_t u16a = 1U;
    uint16_t u16b = 2U;
    uint16_t u16c = 3U;
    uint32_t u32a = 4U;
    uint32_t u32b = 5U;

    u32a = u32a * u16a + u16b;                  /* Compliant: no composite conversion. */
    u32a = (u32a * u16a) + u16b;                /* Compliant: other operand is not wider. */
    u32a = u32a * ((uint32_t)u16a + u16b);      /* Compliant: composite expression is uint32_t. */
    u32a += (u32b + u16b);                      /* Compliant: composite expression is uint32_t. */

    u32a = u32a * (u16a + u16b);                /* Non-compliant: composite converted to uint32_t. */
    u32a += (u16a + u16b);                      /* Non-compliant: composite converted to uint32_t. */
    u32a = (u16a + u16b) + u32b;                /* Non-compliant: composite converted to uint32_t. */

    return (int)(u16c + (uint16_t)u32a);
}
