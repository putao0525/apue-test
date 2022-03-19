#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// 统计一行有多少个字符
//
int main(int argc, char *argv[]) { // 相当于数组的传递
    FILE *fin;
    if (argc < 2) {
        fprintf(stderr, "%s，参数异常", argv[0]);
        exit(EXIT_FAILURE);
    }
    fin = fopen(argv[1], "r");
    if (fin == NULL) {
        perror("文件打开失败");
    }
    int count = 0;
    while (fgetc(fin) != EOF) {
        count++;
    }
    printf("count=%d", count);
    fclose(fin);//在关闭被使用方
    return 0;
}

