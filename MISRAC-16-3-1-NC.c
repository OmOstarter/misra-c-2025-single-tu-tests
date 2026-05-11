/* MISRA C:2025 Rule 16.3 - Non-compliant examples
 * Violations:
 *   1. case 4: a = b;              -- break omitted, falls into case 5
 *   2. case 5: if (a==b){..break}  -- conditional break, not all paths terminate
 *
 * Compliant:
 *   case 0: break;                 -- unconditional break
 *   case 1: / case 2: break;       -- stacked empty labels (grouping)
 *   case 6: abort();               -- _Noreturn function
 *   case 7: continue;              -- continue in loop context
 *   default: break;                -- terminated default
 */

#include <stdlib.h>

int switch_test(int x, int a, int b)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        switch (x)
        {
            case 0:
                break;          /* Compliant*/
            case 1:             /* Compliant*/
            case 2:
                break;          /* Compliant */
            case 4:
                a = b;          /* Non-compliant */
            case 5:
                if (a == b)
                {
                    ++a;
                    break;      /* Non-compliant */
                }
            case 6:
                abort();        /* Compliant  */
            case 7:
                continue;       /* Compliant  */
            default:
                break;          /* Compliant */
        }
    }
    return a;
}

