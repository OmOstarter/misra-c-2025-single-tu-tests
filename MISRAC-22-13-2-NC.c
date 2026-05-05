#include <stdio.h>
#include <threads.h>

int counter = 0; // 共享變數

int increment(void *arg) {
    for (int i = 0; i < 100000; ++i) {
        counter++; // 多執行緒同時修改，可能導致競態條件
    }
    return 0;
}

void main() {
    thrd_t t1, t2;

    // 創建兩個執行緒，執行同樣的任務
    thrd_create(&t1, increment, NULL);
    thrd_create(&t2, increment, NULL);

    // 等待兩個執行緒完成
    thrd_join(t1, NULL);
    thrd_join(t2, NULL);

    // 預期結果應該是 200000
    printf("Final Counter: %d\n", counter);
}
//使用互斥鎖修正 3.c會有示範