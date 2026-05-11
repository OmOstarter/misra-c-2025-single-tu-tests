/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef signed char int8_t;
typedef signed int int32_t;
typedef float float32_t;
typedef double float64_t;
typedef _Complex float cfloat32_t;
typedef _Complex double cfloat64_t;
typedef _Bool bool_t;

static void use_uint16(uint16_t x)
{
    (void)x;
}

static void use_uint32(uint32_t x)
{
    (void)x;
}

static uint8_t foo1(uint16_t x)
{
    return x;                 /* Non-compliant*/
}

int main(void)
{
    enum enuma { A1, A2, A3 } ena;
    enum { K1 = 1, K2 = 128 };
    uint8_t u8a = 0;          /* Compliant by exception. */
    uint8_t u8b = 1U;
    uint8_t u8c = 2U;
    uint16_t u16a = 300U;
    uint32_t u32a = 70000U;
    int8_t s8a = 0;
    int32_t s32a = -1;
    float32_t f32a = 1.0f;
    float64_t f64a = 1.0;
    cfloat32_t cf32a = 0.0f;
    cfloat64_t cf64a = 0.0;
    char cha = 'a';
    bool_t flag = (bool_t)0;

    (void)flag;
    ena = A1;                 /* Compliant */
    s8a = K1;                 /* Compliant*/
    u8a = 2;                  /* Compliant*/
    u32a = u16a;              /* Compliant*/
    use_uint16(u8a);          /* Compliant */
    cf32a = f32a;             /* Compliant*/
    cf64a = f64a;             /* Compliant*/

    u8a = 1.0f;               /* Non-compliant */
    flag = 0;                 /* Non-compliant*/
    cha = 7;                  /* Non-compliant*/
    u8a = 'a';                /* Non-compliant*/
    u8b = 1 - 2;              /* Non-compliant */
    u8c += 'a';               /* Non-compliant*/
    use_uint32(s32a);         /* Non-compliant*/
    f32a = cf32a;             /* Non-compliant */
    f64a = cf64a;             /* Non-compliant */
    s8a = K2;                 /* Non-compliant*/
    u16a = u32a;              /* Non-compliant */
    use_uint16(u32a);         /* Non-compliant */
    cf32a = f64a;             /* Non-compliant */

    switch (u8a)
    {
    case 0:                   /* Compliant by exception. */
        break;
    case 'a':                 /* Non-compliant */
        break;
    case -1:                  /* Non-compliant */
        break;
    default:
        break;
    }

    return (int)foo1(u16a);
}
