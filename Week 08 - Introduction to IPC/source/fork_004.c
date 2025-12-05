// source/fork_004.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int c = 0;
    printf("c == %d\n", c);
    fork();
    c++;
    printf("c == %d\n", c);
    return 0;
}