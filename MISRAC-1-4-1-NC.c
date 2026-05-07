// 啟用 Annex K 功能
#define __STDC_WANT_LIB_EXT1__ 1

#include <stdio.h>
#include <string.h>
#include <time.h> // 為了使用 Annex K 的安全函數

int main(void) {
    char src[10] = "MISRA";
    char dest[10];

    // 1. 使用 strncpy_s (Annex K 的安全函數)
    if (strncpy_s(dest, sizeof(dest), src, sizeof(src)) != 0) {
        printf("Error copying string\n");
    } else {
        printf("Copied string: %s\n", dest);
    }

    // 2. 使用 memcpy_s
    int arr_src[5] = {1, 2, 3, 4, 5};
    int arr_dest[5];
    if (memcpy_s(arr_dest, sizeof(arr_dest), arr_src, sizeof(arr_src)) != 0) {
        printf("Error copying memory\n");
    } else {
        printf("Memory copied successfully\n");
    }

    // 3. 使用 fopen_s
    FILE *file;
    if (fopen_s(&file, "example.txt", "w") != 0) {
        printf("Error opening file\n");
    } else {
        fprintf(file, "MISRA-C Rule 1.4 violated!\n");
        fclose(file);
    }

    // 4. 使用 gets_s
    char input[20];
    printf("Enter a string: ");
    if (gets_s(input, sizeof(input)) == NULL) {
        printf("Error reading input\n");
    } else {
        printf("You entered: %s\n", input);
    }

    return 0;
}
