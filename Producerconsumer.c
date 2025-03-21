#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int buffer[5];
int in = 0;
int out = 0;
int produced_count = 0;
int consumed_count = 0;

sem_t mutex;
sem_t full;
sem_t empty;

void *producer(void *arg)
{
    int item = 1;

    while (produced_count < 20)
    {
        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = item;
        printf("\nProduced: %d", item);
        item++;
        in = (in + 1) % 5;

        produced_count++;

        sem_post(&mutex);
        sem_post(&full);
    }

    pthread_exit(NULL);
}

void *consumer(void *arg)
{
    while (consumed_count < 20)
    {
        sem_wait(&full);
        sem_wait(&mutex);

        int item = buffer[out];
        printf("\nConsumed: %d", item);
        out = (out + 1) % 5;

        consumed_count++;

        sem_post(&mutex);
        sem_post(&empty);
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t producerThread, consumerThread;

    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, 5);

    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);

    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);

    return 0;
}
