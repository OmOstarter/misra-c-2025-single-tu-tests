void f(void) {       // 不合規 - 雖然此函數永不返回，但未聲明為 _Noreturn
    exit(0);         // 調用 exit() 後永不返回
}
