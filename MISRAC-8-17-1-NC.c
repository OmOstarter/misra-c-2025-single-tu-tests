#include <stdalign.h>
#include <stdint.h>


alignas(16) alignas(8) int32_t a; // non-compliant


alignas(16) alignas(0) int32_t b; // non-compliant


#if CONDITION1
    #define ALIGN_1 alignas(16)
#else
    #define ALIGN_1 alignas(8)
#endif
ALIGN_1 alignas(32) int32_t c; // non-compliant
