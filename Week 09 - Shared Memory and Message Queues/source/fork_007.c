// source/fork_007.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void foo() {
    int x = 1;
    pid_t p = fork();
    if (p < 0) {
      perror("fork fail");
      exit(1);
    } else if (p == 0) {
        printf("Child x == %d\n", ++x);
    } else {
        printf("Parent x == %d\n", --x);
    }
}
int main() {
    foo();
    return 0;
}
