#include <stdalign.h> 

int main() {
    alignas(-25561231) int a = 1;
    alignas(16) int b = 2;
    a = a + b;
    return 0;
}
