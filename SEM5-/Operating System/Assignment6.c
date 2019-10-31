#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#include<windows.h> // Header file for Windows OS

// Max Size of Philosophers
#define MAX 5

// States constant for Philosophers
#define STATE_THINKING 1
#define STATE_EATING 2
#define STATE_HUNGRY 3

// To get Left/Right Philosopher Number
#define LEFT (philosopher + 1) % MAX
#define RIGHT (philosopher + 4) % MAX

// Functions Declaration
void* philosopher(void*);
void show_philosopher_state(int);
void set_philosopher_state(int, int);
int can_philosopher_eat(int);
void take_fork(int);
void put_fork(int);
void do_change(int);
void sleep(int);
// END Declarations

sem_t SEM[MAX];
sem_t mutex;
int STATE[MAX];

int main()
{
    int i;
    pthread_t thread_philosopher[MAX];

    // Initialize Mutex
    sem_init(&mutex, 0, 1);

    // Initialize States and Semaphores
    for (i = 0; i < MAX; i++)
    {
        STATE[i] = STATE_THINKING;
        sem_init(&SEM[i], 0, 0);
    }

    // Create Threads
    for (i = 0; i < MAX; i++)
    {
        pthread_create(&thread_philosopher[i], NULL, philosopher, (void*)&i);
        show_philosopher_state(i);
    }

    // Join Threads
    for (i = 0; i < MAX; i++)
    {
        pthread_join(thread_philosopher[i], NULL);
    }

    return 0;
}

// Function to process philosophers
void* philosopher(void *var)
{
    int philosopher = (*(int*)var);

    while (1)
    {
        // Take fork, pause thread for 1 seconds and then put fork.
        take_fork(philosopher);
        sleep(1);
        put_fork(philosopher);
    }
}

// Function to make 'philosopher' hungry and eat.
void take_fork(int philosopher)
{
    // Set WAIT mutex.
    sem_wait(&mutex);

    // Set HUNGRY state for Philosopher
    set_philosopher_state(philosopher, STATE_HUNGRY);

    // Show Philosopher state
    show_philosopher_state(philosopher);

    // Change State of Philosopher
    do_change(philosopher);

    // Set semaphore state again.
    sem_post(&mutex);
    sem_wait(&SEM[philosopher]);

    // Pause thread for 1 seconds.
    sleep(1);
}

// Function to make 'philosopher' thinking and stop eating.
void put_fork(int philosopher)
{
    // Set WAIT for Mutex
    sem_wait(&mutex);

    // Change Philosopher state to THINKING
    set_philosopher_state(philosopher, STATE_THINKING);

    // Show Philosopher State
    show_philosopher_state(philosopher);
  
    // Change State of neighbours of Philosopher
    do_change(LEFT);
    do_change(RIGHT);
    
    // Set POST for mutex and Semaphore
    sem_post(&mutex);
    sem_post(&SEM[philosopher]);

}

// Function to change state of philosopher
void set_philosopher_state(int philosopher, int state)
{
    STATE[philosopher] = state;
}

// Function to Check whether philosopher can eat or not.
int can_philosopher_eat(int philosopher)
{
    if (STATE[philosopher] == STATE_HUNGRY &&
        STATE[LEFT] != STATE_EATING &&
        STATE[RIGHT] != STATE_EATING
    )
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

// Function to display the state of philosopher.
void show_philosopher_state(int philosopher)
{
    printf("\nPhilosopher %d: ", philosopher);

    switch (STATE[philosopher])
    {
        case STATE_THINKING : printf("THINKING"); break;
        case STATE_EATING : printf("EATING"); break;
        case STATE_HUNGRY : printf("HUNGRY"); break;
    }
}

// Function to do changes of Philosopher state
void do_change(int philosopher)
{
    if (can_philosopher_eat(philosopher))
    {
        set_philosopher_state(philosopher, STATE_EATING);
        show_philosopher_state(philosopher);

        // Eat for 2 seconds.
        sleep(2);
    }
    sem_post(&SEM[philosopher]);
}

// Method to use Linux like Sleep method
void sleep(int seconds)
{
    Sleep(seconds * 1000);
}