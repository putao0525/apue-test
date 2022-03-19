#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

//
// 打开文件的场景
//
int main() {
    FILE *fp = NULL;
    //mode 参数是指一个字符串
    fp = fopen("main.c", "r"); // 0666 & ~umask  =xxxx
    if (fp == NULL) {
//        fprintf(stderr, "fopen() faild errno=%d\n", errno);//确定就是知道num
//        perror("fopen()"); //能有自动关联全局的errno
        fprintf(stderr, "fopen():%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    puts("ok"); //相当是往stdout上输出信息
    fclose(fp);// 在堆上分配的内存，此处用来释放掉
    exit(EXIT_SUCCESS);

}

