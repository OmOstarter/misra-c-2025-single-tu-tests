/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

struct Packet
{
    unsigned int length;
    unsigned char data[];    /* Non-compliant */
};

int main(void)
{
    return 0;
}

