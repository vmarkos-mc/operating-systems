#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

typedef struct shared_int {
    int i;
    int turn;
} shared_int;

#define SHM_KEY 1234
#define SHM_SIZE sizeof(shared_int)

int main() {
    int shmid;
    shared_int* counter;
    pid_t pid;
    // Create a shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    // Attach the shared memory segment
    counter = (shared_int*)shmat(shmid, NULL, 0);
    if (counter == (shared_int*)-1) {
        perror("shmat");
        exit(1);
    }
    counter->i = 0;
    counter->turn = 0;
    pid = fork();
    if (pid == 0) { // Child process (turn == 1)
        for (int i = 0; i < 1000000; i++) {
            char* s;
            scanf("%s", s);
            while (counter->turn != 1) {
                continue;
            }
            counter->i++;
            counter->turn = 0;
        }
    } else { // Parent process (turn == 0)
        for (int i = 0; i < 1000000; i++) {
            while (counter->turn != 0) {
                continue;
            }
            counter->i++;
            counter->turn = 1;
        }
        wait(NULL);
    }
    printf("Final counter value: %d\n", counter->i);
    // Detach and remove the shared memory segment
    shmdt(counter);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}