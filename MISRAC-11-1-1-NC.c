/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

typedef void (*FuncPtr)(void);

static void f(void) {}

int main(void)
{
    FuncPtr fp = f;
    void *vp = (void *)fp;   /* Non-compliant*/
    return vp == 0 ? 0 : 1;
}

