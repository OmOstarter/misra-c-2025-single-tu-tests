#define no_op(X) _Generic((X), default: (X))
int main(void){ 
    int a=1; 
    return no_op(a);
}


