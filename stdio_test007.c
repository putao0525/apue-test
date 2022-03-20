#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//
// fflush 强制刷新
// 行缓冲，换行刷新，满的时候刷新，强制刷新（标准输出，因为是终端设备）
// 全缓冲 满的时候刷新，强制刷新，（默认，主要是不是终端设备）
// 无缓冲 stderr ,立即输出
// setvbuf


int main(int argc, char *argv[]) {
    printf("xxxx");
    fflush(stdout);
    while (true) {}
    return 0;
}

