#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//
// 创建一个临时文件名字
// tmpnam  不够安全，临时文件名称，先创建名称，在被多进程使用
// tmpfile 这里是一个匿名的文件，ls 看不到 需要关闭，内存泄漏的影响是ulimit -a
//
int main(int argc, char *argv[]) {

    return 0;
}

