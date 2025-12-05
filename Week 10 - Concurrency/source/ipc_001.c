#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
	pid_t pid = fork();
	if (pid < 0) {
		perror("Failure");
		exit(1);
	} else if (pid == 0) { // Child process
		printf("Child\n");
		exit(0);
	} else { // Parent process
		wait(NULL);
		printf("Parent\n");
	}
	return 0;
}
