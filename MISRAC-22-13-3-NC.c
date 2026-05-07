#include <stdio.h>
#include <threads.h>

int counter = 0;    // 共享變數
mtx_t mutex;        // 互斥鎖

int increment(void *arg) {
    for (int i = 0; i < 100000; ++i) {
        mtx_lock(&mutex);    // 加鎖
        counter++;
        mtx_unlock(&mutex);  // 解鎖
    }
    return 0;
}

void main() {
    thrd_t t1, t2;

    mtx_init(&mutex, mtx_plain); // 初始化互斥鎖

    thrd_create(&t1, increment, NULL);
    thrd_create(&t2, increment, NULL);

    thrd_join(t1, NULL);
    thrd_join(t2, NULL);

    mtx_destroy(&mutex); // 銷毀互斥鎖

    // 確保結果為 200000
    printf("Final Counter: %d\n", counter);
}
