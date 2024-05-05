#include "Headers.h"
#include <pthread.h>
#include <unistd.h>
/*Four Concurrent and Synchronizing Threads
Write a program that generates 4 threads: two withdrawal threads that continue to
withdraw $10 from a bank account and two depositing threads that continue to deposit
$11 to the same account. Assume there is no limit on the maximum balance of the
account but the withdrawal threads should block if the account does not have sufficient
fund (i.e. less than $10) to withdraw.*/
pthread_mutex_t mutex1;
int balance = 0;
void *deposit(void *a)
{
    int tid = *(int *)a;
    for (int i = 0; i < 10; i++)
    {

        sleep(1);
        // printf("At time %d, the balance before depositing thread %d is %d\n", i, tid, balance);

        pthread_mutex_lock(&mutex1);
        printf("At time %d, the balance before depositing thread %d is %d\n", i, tid, balance);
        balance += 11;
        printf("At time % d, the balance after depositing thread %d is %d\n", i, tid, balance);
        pthread_mutex_unlock(&mutex1);

        // printf("At time % d, the balance after depositing thread %d is %d\n", i, tid, balance);

        sleep(1);
    }
    return NULL;
}
void *withdraw(void *a)
{
    int tid = *(int *)a;

    for (int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex1);
        if (balance < 10)
        {
            printf("ERRR\n");
            sleep(1);
            continue;
        }
        else
        {
            // printf("At time %d, the balance for withdrawal thread %d is %d\n", i, tid, balance);

            sleep(1);

            
            printf("At time %d, the balance before withdrawal thread %d is %d\n", i, tid, balance);
            balance -= 10;
            printf("At time % d, the balance after withdrawal thread %d is %d\n", i, tid, balance);
            

            // printf("At time % d, the balance after withdrawal thread %d is %d\n", i, tid, balance);
            sleep(1);
        }
        pthread_mutex_unlock(&mutex1);
    }
    return NULL;
}
int main()
{
    pthread_mutex_init(&mutex1, NULL);

    pthread_t tid[4];

    int arr[] = {1, 2, 3, 4};
    for (int i = 0; i < 2; i++)
        pthread_create(&tid[i], NULL, deposit, (void *)&arr[i]);

    for (int i = 2; i < 4; i++)
        pthread_create(&tid[i], NULL, withdraw, (void *)&arr[i]);

    for (int i = 0; i < 4; i++)
        pthread_join(tid[i], NULL);

    pthread_mutex_destroy(&mutex1);
}