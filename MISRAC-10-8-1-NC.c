/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

typedef signed int int32_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef float float32_t;
typedef double float64_t;
typedef _Complex float cfloat32_t;
typedef _Complex double cfloat64_t;

int main(void)
{
    uint16_t u16a = 1U;
    uint16_t u16b = 2U;
    uint32_t u32a = 3U;
    uint32_t u32b = 4U;
    int32_t s32a = 5;
    int32_t s32b = 6;
    float32_t f32a = 1.0f;
    float32_t f32b = 2.0f;
    cfloat32_t cf32a = 1.0f;
    cfloat32_t cf32b = 2.0f;

    uint16_t ok_narrow = (uint16_t)(u32a + u32b);
    uint16_t bad_category = (uint16_t)(s32a + s32b); /* Non-compliant */
    uint16_t ok_non_composite = (uint16_t)s32a;
    uint32_t bad_wider = (uint32_t)(u16a + u16b); /* Non-compliant */
    cfloat32_t ok_real_to_complex = (cfloat32_t)(f32a + f32b);
    float32_t ok_complex_to_real = (float32_t)(cf32a + cf32b);
    cfloat64_t bad_complex_wider = (cfloat64_t)(f32a + f32b); /* Non-compliant */
    float64_t bad_real_wider = (float64_t)(cf32a + cf32b); /* Non-compliant*/

    (void)ok_narrow;
    (void)bad_category;
    (void)ok_non_composite;
    (void)bad_wider;
    (void)ok_real_to_complex;
    (void)ok_complex_to_real;
    (void)bad_complex_wider;
    (void)bad_real_wider;

    return 0;
}
