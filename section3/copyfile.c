/*
 * =====================================================================================
 *
 *       Filename:  copyfile.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年05月19日 23时54分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  liangxingguang (), liang_xing_guang@163.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "../include/apue.h"

int main(int argc, char** argv) {
    int fd1;
    int fd2;
    int n;
    char buffer[1];
    if (argc <= 2) {
        err_sys("bad arguments,it should be run like copyfile arg1 arg2\n");
        return 1;
    }
    const char * srcFileName = argv[1];
    const char * desFileName = argv[2];
    
    fd1 = open(srcFileName, O_RDWR);
    if (fd1 < 0) {
        err_sys("the %s dose not exists\n", srcFileName);
        exit(0);
    }
    fd2 = open(desFileName, O_RDWR|O_CREAT, FILE_MODE);
    if (fd2 < 0) {
        err_sys("open %s file error\n", desFileName);
    }

    while((n =read(fd1, buffer, sizeof(buffer))) > 0) {
        if (write(fd2, buffer, n) != n) {
            err_sys("copy error\n");
        }
    }
    if (n < 0) {
        err_sys("read the file error\n");
    }
    exit(0);

}
