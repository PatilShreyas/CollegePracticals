#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<windows.h>

#define BUFFER_SIZE 5
#define MAX_PRODUCERS 3
#define MAX_CONSUMERS 3
#define ITEMS 4

void sleep(int);
void* producer(void*);
void* consumer(void*);

// Structure for Shared Buffer
typedef struct
{
    int buffer[BUFFER_SIZE];
    int in;
    int out;
    sem_t full;
    sem_t empty;
    pthread_mutex_t mutex;
}shared_buffer;

// Declare instance of shared_buffer
shared_buffer sbuf;

int main()
{
    int i;
    pthread_t thread_producer[MAX_PRODUCERS];
    pthread_t thread_consumer[MAX_CONSUMERS];

    // Initialize Semaphores
    sem_init(&sbuf.full, 0, 0);
    sem_init(&sbuf.empty, 0, BUFFER_SIZE);
    pthread_mutex_init(&sbuf.mutex, NULL);

    printf("\n----------------------------------------------");
    printf("\nPRODUCER\tCONSUMER\tDATA");
    printf("\n----------------------------------------------");
    // Create Producer Threads
    for (i = 0; i < MAX_PRODUCERS; i++)
    {
        pthread_create(&thread_producer[i], NULL, producer, (void*)i);
    }

    // Create Consumer Threads
    for (i = 0; i < MAX_CONSUMERS; i++)
    {
        pthread_create(&thread_consumer[i], NULL, consumer, (void*)i);
    }

    sleep(10);
    printf("\n----------------------------------------------");
    return 0;
}

void* producer(void *var)
{
    int i, item;

    for (i = 0; i < ITEMS; i++)
    {
        // Produce Item
        item = i;

        // If No Empty slots then WAIT
        sem_wait(&sbuf.empty);

        // If another thread uses buffer then WAIT
        pthread_mutex_lock(&sbuf.mutex);

        // Set Buffer value
        sbuf.buffer[sbuf.in] = item;

        // Change empty slot
        sbuf.in = (sbuf.in + 1) % BUFFER_SIZE;

        // Show Status
        printf("\nP%d\t\t-\t\t%d", var, item);

        // Write all buffered data to its destination
        fflush(stdout);

        // Release the buffer
        pthread_mutex_unlock(&sbuf.mutex);

        // Increment Number of Full slots
        sem_post(&sbuf.full);

        // Interleave Producer Consumer Execution
        if (i % 2 == 1)
        {
            sleep(1);
        }
    }
    return NULL;
}

void* consumer(void *var)
{
    int i, item;

    for (i = ITEMS; i > 0; i--)
    {
        // If slot is full then wait
        sem_wait(&sbuf.full);

        // If another thread uses then WAIT
        pthread_mutex_lock(&sbuf.mutex);

        // Get Buffer Value
        item = sbuf.buffer[sbuf.out];

        // Change full slot
        sbuf.out = (sbuf.out + 1) % BUFFER_SIZE;

        // Show Status of Consumer
        printf("\n-\t\tC%d\t\t%d", var, item);

        // Write all buffered data to its destination
        fflush(stdout);

        // Unlock Thread Mutex
        pthread_mutex_unlock(&sbuf.mutex);

        // Increment Empty slots
        sem_post(&sbuf.empty);

        // Interleave Producer Consumer Execution
        if (i % 2 == 1)
        {
            sleep(1);
        }
    }
    return NULL;
}

// Function to use Linux like 'sleep()' function.
void sleep(int seconds)
{
    Sleep(seconds * 1000);
}

/* OUTPUT:

----------------------------------------------
PRODUCER        CONSUMER        DATA
----------------------------------------------
P0              -               0
P1              -               0
P0              -               1
P1              -               1
P2              -               0
-               C0              0
-               C1              0
-               C2              1
-               C0              1
P2              -               1
-               C1              0
-               C2              1
P0              -               2
P1              -               2
P0              -               3
-               C0              2
P1              -               3
-               C0              2
P2              -               2
-               C2              3
-               C1              3
P2              -               3
-               C2              2
-               C1              3
----------------------------------------------

*/
