/* MISRA C:2025 Rule 17.7 - Non-compliant examples
 * Violations:
 *   1. func(para2);           -- return value discarded
 *
 * Compliant:
 *   2. (void) func(para2);   -- explicitly cast to void
 *   3. x = func(para2);      -- assigned to variable
 */

#include <stdint.h>

static uint16_t func(uint16_t para1)
{
    return para1;
}

static uint16_t x;

void discarded(uint16_t para2)
{
    func(para2);             /* Non-compliant - value discarded */
    (void) func(para2);      /* Compliant */
    x = func(para2);         /* Compliant */
}

int main(void)
{
    discarded(1U);
    return (int)x;
}

