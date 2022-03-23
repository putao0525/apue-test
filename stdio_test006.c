#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//
// 文件的指针，读和写发生在当前的位置
// 往一个文件写入10个字符，在读取写入的10个字符的操作步骤 写操作游标是一直递增的
// fopen() -->fputc()*10-->fclose()-->fopen()-->fgetc()*10

//
// fseek 就是解决这样问题的.
// fseek 场景之一：可以帮我们完成空洞文件，下载文件的大小2G，一开始就占用2G文件,分片下载
// fseek(fp,2g,SEEK_SET)

// SEEK_CUR(文件的开始位置） SEEK_SET SEEK_END(文件的结束位置）
// fopen() -->fputc()-->fseek(fp,-10,SEEK_CUR)-->fgetc()
//
//
// ftell() 获取当前文件的指针
// rewind() 相当于是fseek(fp,0,SEEK_SET)
//



int main(int argc, char *argv[]) {
    FILE *fin;
    if (argc < 2) {
        fprintf(stderr, "命令:%s 收到的参数异常", argv[0]);
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "命令参数:%s\n", argv[1]);
    //需要写绝对路径，否则会报错
    fin = fopen(argv[1], "r");
    if (fin == NULL) {
        perror("文件打开失败");
        exit(EXIT_FAILURE);
    }
    fseek(fin, 0L, SEEK_END);//将文件的指针放到文件的最后
    printf("文件字符的大小:%ld", ftell(fin)); //返回文件指针的位置
    fclose(fin);
    return 0;
}
