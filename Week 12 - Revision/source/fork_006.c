// source/fork_006.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void foo() {
    pid_t p;
    p = fork();
    if (p < 0) {
      perror("Failure");
      exit(1);
    } else if (p == 0) {
        printf("Child!\n");
    } else {
        printf("Parent!\n");
    }
}

int main() {
    foo();
    return 0;
}