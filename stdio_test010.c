#include <stdio.h>

int main(void) {
    if (fseek(stdin, 0, SEEK_CUR) == -1) {
        printf("不可以fseek");
    }
    printf("可以fseek");
    return 0;
}

