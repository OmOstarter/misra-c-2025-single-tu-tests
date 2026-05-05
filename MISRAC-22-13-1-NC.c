#include <threads.h>

mtx_t Ra;                     // 靜態儲存期間的互斥鎖（合規）

int32_t t1(void *ptr) {        // 執行緒入口函數
    mtx_lock(&Ra);             // 合規
    mtx_lock((mtx_t *)ptr);    // 不合規 - 可能操作生命週期已結束的物件
    ...
    mtx_unlock((mtx_t *)ptr);  // 不合規 - 可能操作生命週期已結束的物件
    mtx_unlock(&Ra);           // 合規
    return 0;
}

void main(void) {
    thrd_t id1;                // 不合規 - 自動儲存期間
    mtx_t Rb;                  // 不合規 - 自動儲存期間的互斥鎖
    mtx_init(&Ra, mtx_plain);  // 合規
    mtx_init(&Rb, mtx_plain);  // 初始化互斥鎖（但 Rb 的生命週期不合規）
    thrd_create(&id1, t1, &Rb); // Rb 的生命週期可能已結束
}
