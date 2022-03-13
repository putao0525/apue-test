#include "apue.h"


/**
 * read 函数第一个参数是文件描述符号， read 返回读取的字节数，结束的时候是0 ，失败是小于0
 * read 函数的 第二个参数是 void * 类型，指向了buf 数组，此处是有些疑问
 * 写C的感觉一般使用到的变量需要提前的声明
 *
 */


int main(void) {
    char buf[BUFSIZ];
    int n;
    while ((n = read(STDIN_FILENO, buf, BUFSIZ)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            err_sys("write error");
        }
    }
    if (n < 0) {
        err_sys("read error");
    }

    exit(EXIT_SUCCESS);
}