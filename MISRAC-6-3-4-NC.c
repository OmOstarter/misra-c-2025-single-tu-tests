#include <stdint.h>
int main(void) {

    union U3 {
        uint32_t small: 8;
        uint32_t big  :24;    
    };
    return 0; 
}
