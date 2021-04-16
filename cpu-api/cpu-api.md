# 5 Interlude: Process API

**fork()** **exec()** **wait()**

CRUX: HOW TO CREATE AND CONTROL PROCESSES

## 5.1 The fork() System Call

both are about to return from the fork() system call.

it just comes into life as if it had called fork() itself.

**the child isn’t an *exact* copy:** it now has its own copy of the address space, its own registers, its own PC, and so forth

**return value of fork:** while the parent receives the PID of the newly-created child, the child receives a return code of zero.

the output (of p1.c) is not **deterministic**

## 5.2 The wait() System Call

**the usage of wait: ** it is quite useful for a parent to wait for a child process to finish what it has been doing.**( waitpid() )**

## 5.3 Finally, The exec() System Call

This system call is useful when you want to run a program that is different from the calling program.

**replace: **it **loads** code (and static data) from that executable and overwrites its current code segment (and current static data) with it; the heap and stack and other parts of the memory space of the program are re-initialized.

## 5.4 Why? Motivating The API

**how shell work with those api: **in most cases, the shell then figures out where in the file system the executable resides, calls fork() to create a new child process to run the command, calls some variant of exec() to run the command, and then waits for the command to complete by calling wait().

先fork再exec，wait等待exec结束。

**shell redirection: **when the child is created, before calling exec(), the shell closes **standard output** and opens the file newfile.txt. 

**[What does the “ve” in “execve” mean?](https://stackoverflow.com/questions/50421197/what-does-the-ve-in-execve-mean)**

> p – Uses the PATH environment variable to find the file named in the file >argument to be executed.
>
> v – Command-line arguments are passed to the function as an array (vector) of pointers.

## 5.5 Process Control And Users

**signals subsystem: ** **control-c** sends a SIGINT (interrupt) to the process (normally terminating it) and **control-z** sends a SIGTSTP (stop) signal thus pausing the process in mid-execution (you can resume it later with a command.

**User: **modern systems include a strong conception of the notion of a **user**, Users generally can only control their own processes.



