/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;

static int16_t a1[5] = { -5, -4, -3, -2, -1 };  /* Compliant. */
static int16_t a2[5] = { [0] = -5, [1] = -4, [2] = -3, [3] = -2, [4] = -1 };  /* Compliant. */
static int16_t a3[5] = { [0] = -5, [1] = -4, [2] = -3, [2] = -2, [4] = -1 };  /* Non-compliant. */

static uint16_t *p;

static void f(void)
{
    uint16_t a[2] = { [0] = *p++, [0] = 1 };  /* Non-compliant. */
    (void)a;
}

struct mystruct
{
    int32_t a;
    int32_t b;
    int32_t c;
    int32_t d;
};

static struct mystruct s1 = { 100, -1, 42, 999 };  /* Compliant. */
static struct mystruct s2 = { .a = 100, .b = -1, .c = 42, .d = 999 };  /* Compliant. */
static struct mystruct s3 = { .a = 100, .b = -1, .a = 42, .d = 999 };  /* Non-compliant. */
static struct mystruct s4 = { .b = 2, .c = 3, .a = 1, 4 };  /* Non-compliant. */

int main(void)
{
    return a1[0] + a2[0] + a3[0] + s1.a + s2.a + s3.a + s4.a;
}
