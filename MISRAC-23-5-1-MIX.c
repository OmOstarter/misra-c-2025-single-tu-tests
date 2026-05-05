#include <stdint.h>

void handle_pi  (      int32_t *p);
void handle_cpi (const int32_t *p);
void handle_any (void          *p);

#define handle_pointer1(X) ( _Generic ((X)                     \
                           , const int32_t *: handle_cpi       \
                           , default        : handle_any) (X) )

#define handle_pointer2(X) ( _Generic ((X)                     \
                           , void          *: handle_any       \
                           , const int32_t *: handle_cpi       \
                           , default        : handle_any) (X) )

void test (void)
{
  const int32_t ci = 0;
  int32_t       mi = 0;

  (void)handle_pointer1(&ci);  /* 不應報 MISRA 23.5 */
  (void)handle_pointer1(&mi);  /* 應報：T* 可隱式轉成 const T* */

  (void)handle_pointer2(&mi);  /* 應報：T* 可隱式轉成 void* 或 const T* */
}
