/*
 * =====================================================================================
 *
 *       Filename:  vforktest.c
 *
 *    Description:  the usage of the vfork function
 *
 *        Version:  1.0
 *        Created:  2015年12月05日 16时25分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  liangxingguang (), liang_xing_guang@163.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "../include/apue.h"

int glob = 6;

int
main(void) {
    int var;
    pid_t pid;

    var = 88;

    printf("before vfork\n");

    if ((pid = vfork()) < 0) {
        err_sys("vfork error");
    } else if (pid == 0) {
        glob++;
        var++;
        _exit(0);
    }

    printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
    exit(0);
}

