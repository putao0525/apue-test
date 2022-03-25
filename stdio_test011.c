#include "apue.h"
#include <fcntl.h>

#define FNAME "/tmp/out "

// 需求是下发的 puts函数的输出没有在终端当中，在指定的终端中
// 虚线01下面的内容不可以动

int main(void) {
    int fd;
    fd = open(FNAME, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd < 0) {
        err_sys("open()");
        exit(EXIT_FAILURE);
    }
//    close(1); //fd 本身就是1 ，或者其他的进程在操作
//    dup(fd);
    dup2(fd, 1);
    if (fd != 1) {
        close(fd);
    }
    /****01**** 需要座状态的还原*/
    puts("hello world");
    return 0;
}

