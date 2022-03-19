#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//
// 统计一行有多少个字符？？？
// 如何实现，动态内存来实现，申请一块内存，不如10byte ,快要耗尽的时候扩容，
// 通过malloc 和realloc 实现
//
int main(int argc, char **argv) {
    FILE *fin;
    if (argc < 2) {
        fprintf(stderr, "参数异常");
        exit(EXIT_FAILURE);
    }
    fin = fopen(argv[1], "r");
    if (fin == NULL) {
        perror("fopen()");
    }
    char *lineBuf = NULL;
    size_t lineSize = 0;
    //参数1:二级指针,传递的字符串地址,会将内容放到这个字符串里面
    //参数2:动态的容量大小
    while (true) {
        if (getline(&lineBuf, &lineSize, fin) < 0) {
            break;
        }
        printf("一行有多少个字符:%d，扩容后的容量的大小:%d\n", strlen(lineBuf), lineSize);
    }

    fclose(fin);//一定要关闭
    return 0;
}

