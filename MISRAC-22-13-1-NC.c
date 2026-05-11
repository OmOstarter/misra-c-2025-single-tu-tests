#include <threads.h>

mtx_t Ra;                     // 靜態儲存期間的互斥鎖（合規）

int32_t t1(void *ptr) {        // 執行緒入口函數
    mtx_lock(&Ra);             // compliant
    mtx_lock((mtx_t *)ptr);    // non-compliant
    ...
    mtx_unlock((mtx_t *)ptr);  // non-compliant
    mtx_unlock(&Ra);           // compliant
    return 0;
}

void main(void) {
    thrd_t id1;                // non-compliant
    mtx_t Rb;                  // non-compliant
    mtx_init(&Ra, mtx_plain);  // compliant
    mtx_init(&Rb, mtx_plain);  // 初始化互斥鎖（但 Rb 的生命週期不合規）
    thrd_create(&id1, t1, &Rb); // Rb 的生命週期可能已結束
}
