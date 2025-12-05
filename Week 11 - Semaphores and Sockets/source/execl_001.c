// source/execl_001.c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // display current process id
    printf("\nCurrently running process has PID: %d\n", getpid());
    int error = execl("/usr/bin/ps", "ps", "-l", NULL);
    printf("\nThere was an error during the execl function!\n");
    exit(-1);
}