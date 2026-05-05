#include <stdint.h>
int main(void) {

    union U2{
        uint32_t small:8;
        uint32_t big;
    };
    return 0; 
}
