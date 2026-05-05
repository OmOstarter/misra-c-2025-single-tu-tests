/*
 * MISRA C:2025 rule test.
 * This file is intended for static-analysis testing.  Some non-compliant
 * snippets intentionally trigger compiler diagnostics as well.
 */

typedef unsigned int UINT_16;

enum E
{
    E0 = 0,
    E1 = 1
};

struct S
{
    unsigned int ok_unsigned_int : 2;
    signed int ok_signed_int : 2;
    UINT_16 ok_typedef_unsigned_int : 2;
    int bad_plain_int : 2;       /* Non-compliant: plain int is not permitted. */
    signed long bad_signed_long : 2;   /* Non-compliant: not signed int. */
    unsigned long bad_unsigned_long : 2; /* Non-compliant: not unsigned int. */
    enum E bad_enum : 2;         /* Non-compliant: enum bit-field type. */
};

int main(void)
{
    return 0;
}
