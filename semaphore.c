#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;

void* access_resource(void* arg) {
    int id = *(int*)arg;

    sem_wait(&semaphore);

    printf("Thread %d is accessing the resource\n", id);

    sem_post(&semaphore);

    return NULL;
}

int main() {
    pthread_t threads[4];
    int ids[4];

    sem_init(&semaphore, 0, 1);

    for (int i = 0; i < 4; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, access_resource, &ids[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore);

    return 0;
}
