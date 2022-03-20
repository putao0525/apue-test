#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//
//
// fread 用于读取一个整块对象，小于bufferSize 失败
//
//
//
//
#define BUFSIZE 10

int main(int argc, char *argv[]) {
    FILE *fin, *fout;
    int ch;
    //这部的参数验证可以体验验证，避免资源的浪费
    if (argc < 3) {
        fprintf(stderr, "%s，参数异常", argv[0]);
        exit(EXIT_FAILURE);
    }
    fin = fopen(argv[1], "r");
    if (fin == NULL) {
        perror("打开源文件失败");
        exit(EXIT_FAILURE);
    }
    fout = fopen(argv[2], "w");
    if (fout == NULL) {
        perror("打开目标文件失败");
        exit(EXIT_FAILURE);
    }
    char buf[BUFSIZE];
    int n;
    //成功读取多少个写多少个
    while ((n = fread(buf, 1, BUFSIZ, fin)) > 0) {
        fwrite(buf, 1, n, fout);
    }
    fclose(fout); //先关闭使用方
    fclose(fin);//在关闭被使用方

    return 0;
}

