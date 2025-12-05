// source/fork_003.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    fork();
    fork();
    fork();
    printf("Linux are awesome!\n");
    return 0;
}