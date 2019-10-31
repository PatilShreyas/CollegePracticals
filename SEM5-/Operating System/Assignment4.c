#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<windows.h>

const int MAX = 3;

int data = 0;
int count = 0;

sem_t mutex;
sem_t write_block;

// Function to use Linux like Sleep method in Windows.
void sleep(int seconds)
{
    Sleep(seconds * 1000);
}

// Function to demonstrate READER
void* reader(void *var)
{
    int reader = (*(int*)var);

    // Do WAIT on Mutex
    sem_wait(&mutex);

    // Change/Increment Count
    count++;

    // If count is 1 then WAIT on Write block.
    if (count == 1)
        sem_wait(&write_block);

    // Do POST on mutex.
    sem_post(&mutex);
    
    printf("\n\nREAD DATA (%d)", reader);
    printf("\t\tDATA: %d", data);

    // Do WAIT on mutex.
    sem_wait(&mutex);

    // Change/Decrement count.
    count--;

    // If count is 0 then POST on write block.
    if (count == 0)
        sem_post(&write_block);

    // Do POST on Mutex.
    sem_post(&mutex);
}

// Function to demonstrate WRITER
void* writer(void *var)
{
    int writer = (*(int*)var);

    // Do WAIT on Write Block.
    sem_wait(&write_block);

    // Write/Change Data.
    data++;

    printf("\n\nWRITTEN DATA (%d)", writer);
    printf("\tDATA: %d", data);

    // Do POST on Write block.
    sem_post(&write_block);
}

int main()
{
    int i;
    pthread_t read_thread[MAX];
    pthread_t write_thread[MAX];

    // Initialize Semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&write_block, 0, 1);

    // Create threads
    for (i = 0; i < MAX; i++)
    {
        pthread_create(&write_thread[i], NULL, writer, (void*)&i);
        pthread_create(&read_thread[i], NULL, reader, (void*)&i);
    }

    // Join threads
    for (i = 0; i < MAX; i++)
    {
        pthread_join(write_thread[i], NULL);
        pthread_join(read_thread[i], NULL);
    }
    
    printf("\n");
}
