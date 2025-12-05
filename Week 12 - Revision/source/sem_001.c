#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int shared_counter = 0;
sem_t mutex;

void *increment_counter(void *arg) {
    for (int i = 0; i < 1000000; i++) {
        sem_wait(&mutex);
        shared_counter++;
        sem_post(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    sem_init(&mutex, 0, 1); // Initialize the semaphore to 1
    pthread_create(&thread1, NULL, increment_counter, NULL);
    pthread_create(&thread2, NULL, increment_counter, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Final counter value: %d\n", shared_counter);
    sem_destroy(&mutex);
    return 0;
}