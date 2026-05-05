#include <stdint.h>
int main(void) {

    union U1{
        uint8_t small;
        uint16_t big;
    };
    return 0; 
}
