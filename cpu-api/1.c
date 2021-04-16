// Write a program that calls fork().
// Before calling fork(), have the main process access a variable (e.g., x) 
// and set its value to something (e.g., 100). 

// 1. What value is the variable in the child process? 
// x = 100 in the child process.

// 2. What happens to the variable when both the child and parent change the value of x?
// x = 101 in child, x = 102 in parent.

#include <stdio.h>
#include <stdlib.h> // exit()
#include <unistd.h> // unix std fork()

int main() {
    int x = 100;
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(EXIT_FAILURE);
    } else if (rc == 0) {
        x = 101;
        printf("child value x = %d\n", x);
    } else {
        x = 102;
        printf("parent value x = %d\n", x);
    }
}

// the child isn’t an exact copy: it now has its own copy of the address space, 
// its own registers, its own PC, and so forth.