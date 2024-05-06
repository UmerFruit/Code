#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
using namespace std;
sem_t s1;

void *Eating(void *a)
{
    int id = *(int *)a;
    printf("Customer %d will try to eat.\n", id);

    sem_wait(&s1);
    
    sleep(1);
    printf("Customer %d is now eating.\n", id);
    sleep(1);
    printf("Customer %d has eaten\n\n", id);

    sem_post(&s1);
    
    return NULL;
}

int main()
{
    sem_init(&s1, 0, 10);
    const int Numthreads = 20;
    pthread_t tid[Numthreads];

    int *arr[Numthreads];
    for (int i = 0; i < Numthreads; i++)
    {
        arr[i] =new int( i + 1);
        pthread_create(&tid[i], NULL, Eating, (void *)arr[i]);
    }
    for (int i = 0; i < Numthreads; i++)
    {
        delete arr[i];
        pthread_join(tid[i], NULL);
    }

    sem_destroy(&s1);

    return 0;

}