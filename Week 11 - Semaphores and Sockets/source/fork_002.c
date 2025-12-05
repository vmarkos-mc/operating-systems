// source/fork_002.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    fork();
    printf("Linux are awesome!\n");
    return 0;
}