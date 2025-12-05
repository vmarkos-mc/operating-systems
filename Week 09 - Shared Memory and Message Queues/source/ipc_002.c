#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() { 
    pid_t pid;
    pid = fork();
    if (pid == 0) { // Child 1
        pid = fork();
        if (pid == 0) {
            // Grandchild 1
            printf("Grandchild 1\n");
        } else { // Child 1
            wait(NULL);
            printf("Child 1\n");
        }
    } else {
    // Parent
        pid = fork();
        if (pid == 0) {
            // Child 2
            pid = fork();
            if (pid == 0) {
                // Grandchild 2
                printf("Grandchild 2\n");
            } else {
                // Child 2
                wait(NULL);
                printf("Child 2\n");
            }
        } else {
            // Parent
            wait(NULL); // This refers to Child 2
            wait(NULL); // This refers to Child 1
            printf("Parent\n");
        }
    }
    return 0;
}

/*
The order in which stuff happens is as follows:
* First, the parent process execute, i.e., the else clause (lines 16-36).
* Next, since the parent has to wait (line 32), Child 2 takes over.
* In the same way, since Child 2 (lines 25-29) has to wait, Grandchild 2 takes over.
* Grandchild 2 executes and finishes.
* Then Child 2 resumes and finishes.
* Then, the parent does not have to wait anymore for Child 2 (line 32).
* So, Parent proceeds to line 33, which means it waits for Child 1 (lines 7-15).
* Child 1 then takes over but has to wait for Grandchild 1 (lines 9-12).
* Then, Grandchild 1 takes over and finishes.
* Then, Child 1 takes over and finishes.
* At last, Parent takes over and finishes.
*/