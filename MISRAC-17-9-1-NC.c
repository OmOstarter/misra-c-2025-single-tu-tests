_Noreturn void a(void) {
    return; // 不合規 - 函數不應返回
}

_Noreturn void d(int32_t i) {
    if (i > 0) {
        abort();
    }
    // 不合規 - 如果 i <= 0，函數將返回
}
