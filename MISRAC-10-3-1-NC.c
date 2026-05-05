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
    return x;                 /* Non-compliant: uint16_t to uint8_t. */
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
    ena = A1;                 /* Compliant: same enum. */
    s8a = K1;                 /* Compliant: constant value fits. */
    u8a = 2;                  /* Compliant by exception. */
    u32a = u16a;              /* Compliant: wider unsigned type. */
    use_uint16(u8a);          /* Compliant: wider unsigned parameter. */
    cf32a = f32a;             /* Compliant by exception 4. */
    cf64a = f64a;             /* Compliant by exception 4. */

    u8a = 1.0f;               /* Non-compliant: unsigned and floating. */
    flag = 0;                 /* Non-compliant: boolean and signed. */
    cha = 7;                  /* Non-compliant: character and signed. */
    u8a = 'a';                /* Non-compliant: unsigned and character. */
    u8b = 1 - 2;              /* Non-compliant: negative signed to unsigned. */
    u8c += 'a';               /* Non-compliant: character result to unsigned. */
    use_uint32(s32a);         /* Non-compliant: signed and unsigned. */
    f32a = cf32a;             /* Non-compliant: real and complex. */
    f64a = cf64a;             /* Non-compliant: real and complex. */
    s8a = K2;                 /* Non-compliant: constant value does not fit. */
    u16a = u32a;              /* Non-compliant: uint32_t to uint16_t. */
    use_uint16(u32a);         /* Non-compliant: uint32_t to uint16_t. */
    cf32a = f64a;             /* Non-compliant: complex float narrower than double. */

    switch (u8a)
    {
    case 0:                   /* Compliant by exception. */
        break;
    case 'a':                 /* Non-compliant: unsigned and character. */
        break;
    case -1:                  /* Non-compliant: negative signed to unsigned. */
        break;
    default:
        break;
    }

    return (int)foo1(u16a);
}
