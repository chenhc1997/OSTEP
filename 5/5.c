// Now write a program that uses wait() to wait for the child process to finish in the parent. 
// What does wait() return? What happens if you use wait() in the child?

// On success, returns the process ID(pid_t) of the terminated child; on error, -1 is returned.

// child process returns -1.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(-1);
    } else if (rc > 0) {
        // int wc = wait(NULL);
        // printf("parent wc = %d\n", wc);
    } else {
        int wc = wait(NULL);
        printf("child wc = %d\n", wc);
    }
    return 0;
}

// pid_t wait (int *status); 实际上status也是一个返回值，代表子进程结束状态值