// Write a program that opens a file (with the open() system call) 
// and then calls fork() to create a new process. 

// 1. Can both the child and parent access the file descriptor returned by open()? 
// They both can access the file descriptor.

// 2. What happens when they are writing to the file concurrently, i.e., at the same time?
// parent writes before child, but sometimes they overwrite each other.

#include <fcntl.h> // file control, open()
#include <stdio.h> // 
#include <stdlib.h> // exit()
#include <string.h> // strlen()
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h> // fork(), write(), close()

int main() {
    // 打开文件所采用的操作, 设置文件访问权限
    int fd = open("./2.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU); // file descriptor
    int rc = fork();
    write(fd, "First line.\n", strlen("First line.\n"));

    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(EXIT_FAILURE);
    } else if (rc == 0) {
        write(fd, "child writes a line.\n", strlen("child writes a line.\n"));
        printf("file descriptor in child process: %d\n", fd);
    } else {
        write(fd, "parent writes a line.\n", strlen("parent writes a line.\n"));
        printf("file descriptor in parent prosess: %d\n", fd);

        // 等写完了，把文件内容读到stdout中
        if (wait(NULL) == -1) {
            fprintf(stderr, "wait failed\n");
            exit(EXIT_FAILURE);
        }
        FILE *fp;
        fp = fopen("./2.txt", "r");
        int ch;
        printf("\nfile contents: \n");
        while ((ch = fgetc(fp)) != EOF) printf("%c", ch);
        fclose(fp);
    }

    close(fd);
    return 0;
}