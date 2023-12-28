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

    // char tty[MAX_PATH] = {};
    // for (int nr_tty = 0; nr_tty < 3; nr_tty++) {
    //     snprintf(tty, sizeof(tty), "/dev_tty%d", nr_tty);
    //     int stdin  = open(tty, O_RDWR);
    //     int stdout = open(tty, O_RDWR);
    //     int stderr = open(tty, O_RDWR);
    // }
    int i = 0;
    // global ++;
    int j = 0;

    printf("good\n");
    while (i < 3) {
        
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
            printf("i am %d", i);
        }
    }
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
