/*
 * =====================================================================================
 *
 *       Filename:  lseektest.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年05月19日 23时22分47秒
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
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1) {
        printf("cannot seek.\n");
    } else {
        printf("seek Ok\n");
    }
    exit(0);
}
