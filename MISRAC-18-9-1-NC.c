/* rule18_9_test.c */
#include <stdint.h>
#include <stdio.h>

/*--------------------------------------
 * 型別與輔助函式
 *------------------------------------*/
struct S1 {
    int32_t array[10];
};

/* 全域具名物件：生命期 = 程式整段執行期間 */
static struct S1 s1;

/* 回傳「臨時」S1：呼叫端只能取得一份 *temporary value* */
static struct S1 getS1(void)
{
    struct S1 tmp = { {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} };
    return tmp;                 /* 回傳後 tmp 會被複製到暫存區，再銷毀 */
}

static void foo(const int32_t *p)
{
    /* 這裡僅示範：實務可對 p 做讀取等操作 */
    printf("foo(): first element = %d\n", p[0]);
}

/*--------------------------------------
 * 測試主程式
 *------------------------------------*/
int main(void)
{
    int32_t *p;
    int32_t  j;

    /* ========= 合規示範 ========= */
    p = s1.array;               /* OK：具名物件，array-to-pointer 合法 */
    s1.array[0] = 1;            /* OK：可修改 lvalue */
    foo(s1.array);              /* OK：指標生命期與 s1 同步 */

    /* ========= 不合規示範 ========= */
    p = getS1().array;          /* ✗ 產生懸空指標（Rule 18.9 違規） */
    /* 接下來即使不解參，也已屬未定義行為；若你真的要查看，可攔住靜
       態分析器報告即可，執行期結果無保證。 */
    foo(getS1().array);         /* ✗ 透過懸空指標傳參 */
    /* 立即索引（唯讀）是允許的 —— 下面兩行合規 */
    j = getS1().array[3];       /* OK：只讀取值 */
    j = (s1 = s1).array[3];     /* OK：同樣只讀 */
    /* 但寫入就不行 */
    getS1().array[3] = j;       /* ✗ 未定義行為（Rule 18.9 違規） */

    (1 ? s1 : s1).array[3] = j; /* ✗ 非 lvalue 結果，仍屬違規 */

    return 0;
}
