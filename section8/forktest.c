/*
 * =====================================================================================
 *
 *       Filename:  forktest.c
 *
 *    Description:  the useage of fork function in linux from apue
 *
 *        Version:  1.0
 *        Created:  2015年12月05日 15时38分14秒
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
char buf[] = "a write to stdout\n";

int
main(void) {
    int var;
    pid_t pid;

    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1){
        err_sys("write error");
    }

    printf("before fork\n");

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        // fork return from child
        printf("in the child process\n");
        glob++;
        var++;
    } else {
        //fork return from parent
        printf("int the parent process\n");
        sleep(2);
    }
    
    printf("pid = %d, glob = %d, var = %d\n", getpid(), glob,var);
    exit(0);
}
