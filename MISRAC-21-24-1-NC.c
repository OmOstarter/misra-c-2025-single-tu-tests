#include <stdlib.h>

void generateRandomNumber(void) {
    srand(42);            // non-compliant
    int r = rand();       // non-compliant
}
