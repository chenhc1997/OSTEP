// Write a program that calls fork() 
// and then calls some form of exec() to run the program /bin/ls. 
// See if you can try all of the variants of exec(), 
// including (on Linux) execl(), execle(), execlp(), execv(), execvp(), and execvpe(). 
// Why do you think there are so many variants of the same basic call?

#include <stdio.h>
#include <stdlib.h>  // exit
#include <unistd.h>  // fork, exec*

int main() {
    int rc = fork();

    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(EXIT_FAILURE);
    } else if (rc == 0) {
        char *argvs[] = {"ls", "-l", "-a", "-h", NULL};
        char *envp[] = {NULL};

        execl("/bin/ls", "ls", "-l", "-a", "-h", NULL);
        execlp("ls", "ls", "-l", "-a", "-h", NULL);
        execle("/bin/ls", "ls", "-l", "-a", "-h", NULL, envp);

        execv("/bin/ls", argvs);
        execvp("ls", argvs);
    }
    return 0;
}

// e – An array of pointers to environment variables is explicitly passed to the new process image.
// l – Command-line arguments are passed individually (a list) to the function.
// p – Uses the PATH environment variable to find the file named in the file argument to be executed.
// v – Command-line arguments are passed to the function as an array (vector) of pointers.