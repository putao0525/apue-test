#include <stdio.h>
#include <sys/fcntl.h>
#include "apue.h"

void testFseek01(void) {
    if (fseek(stdin, 0, SEEK_CUR) == -1) {
        printf("不可以fseek");
    }
    printf("可以fseek");
}
//cmake-build-debug [master●] % ls -al file.hole
//-rw-r--r--  1 putao  staff  16394 Mar 23 13:30 file.hole

// -c 以字符的形式打开
//cmake-build-debug [master●] % od -c file.hole
//0000000    a   b   c   d   e   f   g   h   i   j  \0  \0  \0  \0  \0  \0
//0000020   \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
//*
//0040000    A   B   C   D   E   F   G   H   I   J
//0040012
//cmake-build-debug [master●] %


void testFseek02(void) {
    int fd;
    char buf1[] = "abcdefghij";
    char buf2[] = "ABCDEFGHIJ";

    if ((fd = creat("file.hole", FILE_MODE)) < 0) {
        err_sys("创建异常");
    }
    if ((write(fd, buf1, 10)) != 10) {
        err_sys("buf1写出错");
        //此时,offset=10
    }
    //空洞文件
    if (lseek(fd, 16384, SEEK_SET) == -1) {
        err_sys("fseek 出错");
        //此时,offset =16384
    }
    if (write(fd, buf2, 10) != 10) {
        err_sys("buf2写出错");
        //此时,offset =16394
    }
}

int main(void) {
//    testFseek01();
    testFseek02();
    return 0;
}

