// source/shmem_001.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_KEY 1234
#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shm_addr;
    pid_t pid;
    // Create a shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    // Attach the shared memory segment
    shm_addr = (char *)shmat(shmid, NULL, 0);
    if (shm_addr == (char *) -1) {
        perror("shmat");
        exit(1);
    }
    pid = fork();
    if (pid == 0) { // Child process
        // Read from shared memory
        printf("Child process: %s\n", shm_addr);
    } else { // Parent process
        // Write to shared memory
        strcpy(shm_addr, "Parent process!");
    }
    // Detach the shared memory segment
    shmdt(shm_addr);
    // Remove the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}