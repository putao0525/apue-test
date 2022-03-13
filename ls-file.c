#include <stdio.h>
#include <dirent.h>
#include <apue.h>

int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dirp;
    if (argc != 2)
        err_quit("参数不合法，请输入目录");
    if ((dp = opendir(argv[1])) == NULL)
        err_sys("不可以打开目录:%s", argv[1]);
    while ((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp->d_name);
    closedir(dp);
    exit(0);
}