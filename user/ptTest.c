#include "proto.h"
#include <stdio.h>

int global = 0;

char *str2, *str3;

void pthread_test1() {
    int i;
    // pthread(pthread_test2);
    while (1) {
        printf("pth1");
        printf("%d", ++global);
        printf(" ");
        i = 10000000;
        while (--i) {}
    }
}

/*======================================================================*
                          Syscall Pthread Test
added by xw, 18/4/27
 *======================================================================*/

int main(int arg, char *argv[]) {

    int i = 0;
    global ++;
    int j = 0;
    
    // printf("exec!");
    // if (exec("/orange/ptTest.bin") == -1) {
    //     printf("good ");// test good's mental state
    // }// test exec

    // test fork begin
    while (i < 13) {
        
        if (fork() == 0) {
            i++;
            continue;
        }
        break;
    }
    while (1) {
        j++;
        if (j == 100000000) {
            j = 0;
            global = 2;
            printf("i am %d global = %d\n", i, global);
        }
    }
    // test fork end
    pthread(pthread_test1);
    while (1) {
        printf("init");
        printf("%d", ++global);
        printf(" ");
        i = 10000000;
        while (--i) {}
    }
    return 0;
}
