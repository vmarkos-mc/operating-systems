#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_KEY 1234
#define SHM_SIZE sizeof(int)

int main() {
    int shmid;
    int *counter;
    pid_t pid;
    // Create a shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    // Attach the shared memory segment
    counter = (int*)shmat(shmid, NULL, 0);
    if (counter == (int*)-1) {
        perror("shmat");
        exit(1);
    }
    *counter = 0;
    pid = fork();
    if (pid == 0) { // Child process
        for (int i = 0; i < 1000000; i++) {
            (*counter)++;
        }
    } else { // Parent process
        for (int i = 0; i < 1000000; i++) {
            (*counter)++;
        }
        wait(NULL);
    }
    printf("Final counter value: %d\n", *counter);
    // Detach and remove the shared memory segment
    shmdt(counter);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}