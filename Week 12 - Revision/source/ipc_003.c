#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Failure");
        exit(1);
    } else if (pid == 0) { // Child process
        execlp("ls", "ls", "-la", NULL);
        perror("execlp");
        exit(1);
    } else { // Parent process
        wait(NULL);
        printf("Child process finished.\n");
    }
    return 0;
}