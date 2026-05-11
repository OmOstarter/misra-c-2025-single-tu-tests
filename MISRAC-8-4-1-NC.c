/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

#include <stdint.h>

extern int16_t count;
int16_t count = 0;             /* Compliant. */

extern uint16_t speed = 6000u; /* Non-compliant*/
uint8_t pressure = 101u;       /* Non-compliant*/

extern void func1(void);
extern void func2(int16_t x, int16_t y);
extern void func3(int16_t x, int16_t y);

void func1(void)
{
}

void func2(int16_t x, int16_t y)
{
    (void)x;
    (void)y;
}

void func3(int16_t x, uint16_t y) /* Non-compliant*/
{
    (void)x;
    (void)y;
}

void func4(void)                /* Non-compliant*/
{
}

static void func5(void)         /* Compliant: internal linkage. */
{
}

int main(void)                  /* Compliant: main exception. */
{
    func1();
    func2(count, (int16_t)speed);
    func4();
    func5();
    return pressure;
}
