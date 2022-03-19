#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// 这是一个 复制文件的场景，一个字符一个字符的复制
// C语言还是要多写注释，并且要多复习
//
int main(int argc, char *argv[]) { // 相当于数组的传递
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
    while (1) {
        ch = fgetc(fin);
        if (ch == EOF) { // 有宏定义的 优先使用宏定义
            break;
        }
        fputc(ch, fout);
    }
    fclose(fout); //先关闭使用方
    fclose(fin);//在关闭被使用方
}

