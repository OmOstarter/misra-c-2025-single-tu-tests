_Noreturn void a(void) {
    return; /* Non-compliant */

}

_Noreturn void d(int32_t i) {
    if (i > 0) {
        abort();
    }
    /* Non-compliant */

