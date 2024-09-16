#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <queue>
using namespace std;


pthread_mutex_t mutex1;

queue<int> p1, p2;
int npages1, npages2;
void *printer1(void *a)
{
    while (!p1.empty())
    {
        sleep(1);
        if (npages1 == 0)
        {
            printf("Printer 2 is waiting for paper\n");
            continue;
        }
        pthread_mutex_lock(&mutex1);
        int task = p1.front();
        p1.pop();
        for (int i = 0; i < task; i++)
        {
            if (npages1 != 0)
            {
                npages1--;
            }
            else
            {
                printf("Printer 1 is out of paper\n");
                task = task-i;
                p1.push(task);
                break;
            }
        }
        pthread_mutex_unlock(&mutex1);
        
    }
    return NULL;
}
void *printer2(void *a)
{
    while (!p2.empty())
    {
        sleep(1);
        if (npages2 == 0)
        {
            printf("Printer 2 is waiting for paper\n");
            continue;
        }
        pthread_mutex_lock(&mutex1);
        int task = p2.front();
        p2.pop();
        for (int i = 0; i < task; i++)
        {
            if (npages2 != 0)
            {
                npages2--;
            }
            else
            {
                printf("Printer 2 is out of paper\n");
                task = task-i;
                p2.push(task);
                break;
            }
        }
        pthread_mutex_unlock(&mutex1);
        
    }
    return NULL;
}
void *labour(void *a)
{
    while (1)
    {
        if (!p1.empty())
        {
            sleep(1);
            pthread_mutex_lock(&mutex1);
            printf("Adding paper to P1\n");
            npages1 += 5;
            pthread_mutex_unlock(&mutex1);
        }
        if (!p2.empty())
        {
            sleep(1);
            pthread_mutex_lock(&mutex1);
            printf("Adding paper to P2\n");
            npages2 += 5;
            pthread_mutex_unlock(&mutex1);
        }
        if (p1.empty() && p2.empty())
        {
            break;
        }
    }
    return NULL;
}
int main()
{
    pthread_mutex_init(&mutex1, NULL);

    for (int i = 0; i < 10; i++)
    {
        srand(time(NULL));
        p1.push(rand() % 20 + 10);
        p2.push(rand() % 20 + 10);
    }

    pthread_t t1, t2, l;

    int arr[] = {1, 2};

    npages1 = rand() % 30;
    npages2 = rand() % 30;

    pthread_create(&t1, NULL, printer1, (void *)&arr[0]);
    pthread_create(&t2, NULL, printer2, (void *)&arr[1]);
    pthread_create(&l, NULL, labour, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(l, NULL);

    pthread_mutex_destroy(&mutex1);
}