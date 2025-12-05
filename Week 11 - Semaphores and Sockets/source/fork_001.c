// source/fork_001.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t p = fork(); // fork this process
    if (p<0) { // In case of failure..
      perror("fork fail"); // print an error
      exit(1); // and exit with statuscode == 1
    }
    // Otherwise print a relevant message
    printf("process_id(pid) = %d \n", getpid());
    return 0;
}