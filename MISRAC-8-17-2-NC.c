#include <stdalign.h>
#include <stdint.h>

alignas(16) alignas(8) alignas(4) alignas(2) int32_t a; // non-compliant

int main(){

}