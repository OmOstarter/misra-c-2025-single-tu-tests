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
  filter_ints(s16 + s16);  /* 預期：違反 23.6（essential short vs int） */
  filter_ints('c');        /* 預期：違反 23.6（essential char vs int） */
  filter_ints(s16);        /* OK */
  filter_ints(i32);        /* OK */
  filter_ints(l32);        /* OK */
  filter_ints(10u);        /* 預期：例外，不報 23.6 */
  filter_ints(250 + 350);  /* 如果常數折疊，預期：例外，不報 23.6 */
  filter_ints(e);          /* 預期：違反 23.6（essential enum vs unsigned int） */
  filter_ints(A);          /* 若 A 被視為 enum expr，預期：違反 23.6 */
}
