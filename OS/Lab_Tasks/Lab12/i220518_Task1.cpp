#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
using namespace std;
sem_t s1;

void *Crossing(void *a)
{
    int id = *(int *)a;
    printf("Trying to cross with car: %d\n", id);

    sem_wait(&s1);
    
    sleep(1);
    printf("Crossing with car: %d\n", id);
    sleep(1);
    printf("Car: %d has crossed\n\n", id);

    sem_post(&s1);
    
    return NULL;
}

int main()
{
    sem_init(&s1, 0, 3);
    pthread_t tid[15];

    int *arr[15];
    for (int i = 0; i < 15; i++)
    {
        arr[i] =new int( i + 1);
        pthread_create(&tid[i], NULL, Crossing, (void *)arr[i]);
    }
    for (int i = 0; i < 15; i++)
    {
        delete arr[i];
        pthread_join(tid[i], NULL);
    }

    sem_destroy(&s1);

    return 0;

}