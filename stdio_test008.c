#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//
//  char *gets(char * s) 不检查缓存区的溢出
//  char *fgetc(char *s,int size,FIFE *stream);指定到s,大小是size 行缓冲
//  size-1 和 '\n' 结束
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
    while (fgets(buf, BUFSIZ, fin) != NULL) { // buf 就已经是地址了
        fputs(buf, fout);
    }
    fclose(fout); //先关闭使用方
    fclose(fin);//在关闭被使用方

    return 0;
}

