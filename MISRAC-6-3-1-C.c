#include <stdint.h>
int main(void) {

    union test{
        struct {
            uint8_t a:4;
            uint8_t b:4;
            uint8_t c:4;
            uint8_t d:4;  
        } q;
        uint16_t r;
    };
    return 0; 
}
