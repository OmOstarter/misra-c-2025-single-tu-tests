#include <stdlib.h>

void generateRandomNumber(void) {
    srand(42);            // 不合規 - 禁止使用 srand
    int r = rand();       // 不合規 - 禁止使用 rand
}
