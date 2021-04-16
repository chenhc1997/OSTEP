// Write another program using fork(). 
// The child process should print “hello”; the parent process should print “goodbye”. 
// You should try to ensure that the child process always prints first; 
// can you do this without calling wait() in the parent?
// Using kill() to send SIGCONT signal to parent process.

#include <signal.h> // kill()
#include <unistd.h> // fork(), getpid(), pause()
#include <stdio.h>

static void sigcont_handler() { printf("goodbye\n"); }

int main() {
    int parent_pid = getpid();
    int rc = fork();
    struct sigaction act;
    act.sa_handler = sigcont_handler;

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
    } else if (rc == 0) {
        printf("child: hello\n");
        kill(parent_pid, SIGCONT);
    } else {
        sigaction(SIGCONT, &act, NULL);
        pause();
    }
    return 0;
}