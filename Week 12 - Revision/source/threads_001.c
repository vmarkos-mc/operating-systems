// source/threads_001.c
#include <stdio.h>
#include <pthread.h>

void *my_thread(void *arg) {
    printf("Hello from thread!\n");
    return NULL;
}

int main() {
    pthread_t thread_id;

    pthread_create(&thread_id, NULL, my_thread, NULL);
    pthread_join(thread_id, NULL);

    printf("Hello from main thread!\n");

    return 0;
}