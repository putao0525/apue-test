#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

//
// fopen() fclose()
// 打开文件的场景
// fprintf 第一个参数类型于重定向
//
//

int main() {
    char str[] = "123a45";
    printf("%d\n", atoi(str));
    char buf[1024];
    int year = 2014, month = 3, day = 12;
    sprintf(buf, "%d-%d-%d", year, month, day);
    puts(buf);

    FILE *fp = NULL;
    //mode 参数是指一个字符串
    fp = fopen("main.c2", "r"); // 0666 & ~umask  =xxxx
    if (fp == NULL) {
        fprintf(stderr, "fopen() faild errno=%d\n", errno);//确定就是知道num
//        perror("fopen()"); //能有自动关联全局的errno
//        fprintf(stderr, "fopen():%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    puts("ok"); //相当是往stdout上输出信息
    fclose(fp);// 在堆上分配的内存，此处用来释放掉
    exit(EXIT_SUCCESS);

}

