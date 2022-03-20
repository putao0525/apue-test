#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// fgetc() 成功的话是无符号的char型转成int类型 ， 返回EOF 失败或者结束
// getc() 定义成宏，内核为了加快时间，应用编程为了稳定
// fgetchar()  从getc() 从标准输入中读取数据
// 统计一个文件的字符总数
//
int main(int argc, char *argv[]) { // 相当于数组的传递
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
    int count = 0;
    while (fgetc(fin) != EOF) {
        count++;
    }
    printf("count=%d", count);
    fclose(fin);//在关闭被使用方
    return 0;
}

