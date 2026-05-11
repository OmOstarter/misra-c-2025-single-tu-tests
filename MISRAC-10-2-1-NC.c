/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

int main(void)
{
    typedef unsigned char uint8_t;
    typedef signed char int8_t;
    typedef short int16_t;
    typedef float float32_t;
    enum E { E0 } ena = E0;

    uint8_t u8a = 1U;
    int8_t s8a = 1;
    int16_t s16a = 1;
    float32_t f32a = 1.0f;
    char cha = 'a';

    (void)('0' + u8a);       /* Compliant*/
    (void)(s8a + '0');       /* Compliant*/
    (void)(cha + 1);         /* Compliant*/
    (void)(1 + cha);         /* Compliant*/
    (void)(cha - '0');       /* Compliant*/
    (void)('0' - s8a);       /* Compliant*/
    (void)(cha - 1);         /* Compliant */

    (void)(s16a - 'a');      /* Non-compliant*/
    (void)('0' + f32a);      /* Non-compliant */
    (void)(cha + ':');       /* Non-compliant*/
    (void)(cha - ena);       /* Non-compliant*/

    return 0;
}
