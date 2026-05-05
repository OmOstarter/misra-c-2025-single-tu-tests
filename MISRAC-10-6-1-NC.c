/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

static void use_uint32(uint32_t x)
{
    (void)x;
}

int main(void)
{
    uint8_t u8a = 1U;
    uint8_t u8b = 2U;
    uint16_t u16a = 1U;
    uint16_t u16b = 2U;
    uint16_t u16c = u16a + u16b;             /* Compliant: same essential type. */
    uint16_t u16d = u8a + u8b;               /* Non-compliant: initialization to wider type. */
    uint32_t u32a = (uint32_t)u16a + u16b;   /* Compliant: cast makes composite uint32_t. */

    u32a = u16a + u16b;                      /* Non-compliant: assigned to wider type. */
    use_uint32(u16a + u16b);                 /* Non-compliant: argument conversion to wider type. */
    u16c = u8a + u8b;                        /* Non-compliant: assignment to wider type. */

    return (int)(u16c + u16d + (uint16_t)u32a);
}
