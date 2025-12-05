#include <stddef.h> // Standard type definitions
#include <stdlib.h> // General purpose functions
#include <unistd.h> // Standard symbolic constants and types
#include <sys/types.h> // Used to access data types
#include <sys/wait.h> // Used to wait for things
#include <stdio.h> // Used for IO operations
#define SHELL "/bin/sh" // Define path to shell

int my_system (const char *command) {
    // `command` is a pointer to a command string
    int status; // Exit status
    pid_t pid; // `pid_t` is a type of "process ID"
    pid = fork();
    /*
    The Fork system call is used for creating a new process in Linux,
    and Unix systems, which is called the child process, which runs
    concurrently with the process that makes the fork() call (parent process).
    After a new child process is created, both processes will execute the
    next instruction following the fork() system call. The child process
    uses the same pc(program counter), same CPU registers, and same open
    files which use in the parent process. It takes no parameters and
    returns an integer value.

    Output --> int:
    *  < 0 --> Child process creation failed
    * == 0 --> Returned to the newly created child process
    *  > 0 --> Returned to parent or caller. The value contains the process ID of
    *          the newly created child process
    */
    char cmd[256];
    if (pid == 0) { // Newly created child process
        execl(SHELL, SHELL, "-c", command, NULL);
        /*
        The execl() function is used to replace the currently running process with
        another process. When the running process calls the execl() function, its
        process image gets overwritten with the process specified within the
        execl() function.

        Syntax:
        int execl (const char *Path, const char *Argument0, const char *Argument1, ... , NULL);

        Arguments:
        * Path: This represents the path to the binary file or program we want
          to run instead of the current process. The path to the program must be
          an absolute path instead of a relative one.
        * Argument list: Any arguments we want to pass on to the program should be
          included in the function as char pointers separated by commas. In the
          syntax, we only passed two arguments, Argument0 and Argument1. However,
          we can pass as many arguments as we deem necessary.
        * NULL: At the end of the function, we will always use NULL to represent
          the end of the arguments.

        Output    --> nothing or -1
        * -1      --> Failure
        * nothing --> The calling process has entirely been overwritten by the new one
        
        REMARK: In case execl() does not fail no lines below it will execute, as the new process
        has entirely replaced the calling one.

        EXAMPLE: In the above case we have written:

        ```c
            execl(SHELL, SHELL, "-c", command, NULL);
        ```

        That means that:
        * we are calling SHELL, i.e., /bin/sh, as the executable application (Path);
        * we then pass SHELL, "-c" and the user provided command as arguments, which actually
          executes the command at hand (sh -c <command>);
        * NULL, which terminates the arguments list.

        From man sh (regarding -c):
        'Read commands from the command_string operand instead of from the standard input.
        Special parameter 0 will be set from the command_name operand and the positional
        parameters ($1, $2, etc.) set from the remaining argument operands.'
        */
        _exit(EXIT_FAILURE); // Terminate the calling process
    }
    else if (pid < 0) { // Child process creation failed
        status = -1;
    }
    else if (waitpid(pid, &status, 0) != pid) {
        /*
        The waitpid() system call suspends execution of the calling process until a
        child specified by pid argument has changed state. By default, waitpid()
        waits only for terminated children, but this behavior is modifiable via the
        options argument.

        The value of pid can be:
        *  < -1
            meaning wait for any child process whose process group ID is equal to the
            absolute value of pid.
        * == -1
            meaning wait for any child process.
        * == 0
            meaning wait for any child process whose process group ID is equal to that of
            the calling process.
        *  > 0
            meaning wait for the child whose process ID is equal to the value of pid.
        */
        status = -1;
    }
    return status; // This returns only in case things have failed in some way
}

int main() {
    char cmd[256]; // Char buffer for the input command
    while (1) {
        printf("input command: ");
        scanf("%s", cmd); // Read command
        my_system(cmd); // Try to execute it
    }
    return 0;
}