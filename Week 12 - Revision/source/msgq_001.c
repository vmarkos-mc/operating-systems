#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <string.h>
#define MSG_KEY 1234

struct message {
    long mtype;
    char mtext[100];
};

int main() {
    int msqid;
    struct message msg;
    pid_t pid;
    // Create a message queue
    msqid = msgget(MSG_KEY, IPC_CREAT | 0666);
    if (msqid == -1) {
        perror("msgget");
        exit(1);
    }
    pid = fork();
    if (pid == 0) { // Child process
        // Receive the message
        msgrcv(msqid, &msg, sizeof(msg.mtext), 1, 0);
        printf("Child received: %s\n", msg.mtext);
    } else { // Parent process
        // Send a message
        msg.mtype = 1;
        strcpy(msg.mtext, "Parent Process!");
        msgsnd(msqid, &msg, sizeof(msg.mtext), 0);
        wait(NULL);
    }
    // Remove the message queue
    msgctl(msqid, IPC_RMID, NULL);
    return 0;
}