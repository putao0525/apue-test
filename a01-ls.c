#include <stdio.h>
#include <dirent.h>
#include <apue.h>

/**
 * argc 默认是一个参数，输入一个参数后是2个参数
 * 在函数声明，写指针的时候，一般是结构体，然后是 *. 例如 DIR * dir
 *
 */

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *dirent;
    if (argc != 2)
        err_quit("参数不合法，请输入一个参数");
    if ((dir = opendir(argv[1])) == NULL)
        err_sys("不可以打开目录:%s", argv[1]);
    while ((dirent = readdir(dir)) != NULL)
        printf("%s\n", dirent->d_name);
    closedir(dir);
    exit(EXIT_SUCCESS);
}