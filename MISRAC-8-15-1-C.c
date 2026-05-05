#include <stdint.h>
#include <stdio.h>
#include <stdalign.h>
#include "MISRAC-8-15-1.h"
alignas (16) int32_t a;

int main(){
    a = 10;
    printf("%d\n",a);
}