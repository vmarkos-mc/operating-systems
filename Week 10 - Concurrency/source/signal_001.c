// source/signal_001.c
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void signal_handler(int sig) {
    printf("Child process received signal %d\n", sig);
}

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) { // Child process
        signal(SIGUSR1, signal_handler);
        pause(); // Wait for signal
    } else { // Parent process
        sleep(2); // Wait for a bit
        kill(pid, SIGUSR1); // Send SIGUSR1 to the child
        wait(NULL);
    }
    return 0;
}