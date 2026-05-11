#include <stdint.h>

#define filter_ints(X) ( _Generic((X)                      \
                       ,   signed short: handle_sshort     \
                       , unsigned short: handle_ushort     \
                       ,   signed int  : handle_sint       \
                       , unsigned int  : handle_uint       \
                       ,   signed long : handle_slong      \
                       , unsigned long : handle_ulong      \
                       , default       : handle_any) (X) )

void handle_sshort(signed short);
void handle_ushort(unsigned short);
void handle_sint(signed int);
void handle_uint(unsigned int);
void handle_slong(signed long);
void handle_ulong(unsigned long);
void handle_any(int);

short s16 = 0;
int   i32 = 0;
long  l32 = 0;

enum E { A = 0, B = 1, C = 2 };
enum E e = A;

void test(void)
{
  filter_ints(s16 + s16);  // non-compliant
}
