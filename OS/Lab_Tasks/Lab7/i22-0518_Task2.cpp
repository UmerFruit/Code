#include <iostream>
#include <pthread.h>
using namespace std;
int arr[30];
void *sum(void *arg)
{
    int sum = 0;
    for (int i = 0; i < 30; i++)
        sum += arr[i];

    pthread_exit((void *)sum);
}
void *prod(void *arg)
{
    int prod = 1;
    for (int i = 0; i < 30; i++)
        prod *= arr[i];
    pthread_exit((void *)prod);
}
int main()
{

    for (int i = 0; i < 30; i++)
        arr[i] = i + 1;

    pthread_t t1, t2;

    pthread_create(&t1, NULL, sum, NULL);
    pthread_create(&t2, NULL, prod, NULL);

    void *status1;
    void *status2;

    pthread_join(t1, &status1);
    pthread_join(t2, &status2);
    printf("In main thread1 returned value is %ld \n", status1);
    printf("In main thread1 returned value is %ld \n", status2);
}