/*
 * =====================================================================================
 *
 *       Filename:  lseektest1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年05月19日 23时28分14秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  liangxingguang (), liang_xing_guang@163.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "../include/apue.h"

int
main(void) {
    char * str = "this is example for open and write function\n";
    int fd = open("lseek.log", O_RDWR|O_CREAT, FILE_MODE);
    if (fd == -1) {
        err_sys("open file error");
    }

    write(fd, str, strlen(str) + 1);

    str = "this is a example for lseek function\n";
    lseek(fd, 300, SEEK_CUR);
    write(fd, str, strlen(str) + 1);
    close(fd);
    exit(0);
}

