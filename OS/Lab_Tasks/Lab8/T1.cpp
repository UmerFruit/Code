#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
using namespace std;
int arr[20], key;
void *array_sum(void *arg)
{
    long long sum = 0;

    for (int i = 0; i < 20; i++)
    {
        sum += arr[i];
    }
    cout << "Sum = " << sum << endl;
    return NULL;
}
void *array_mul(void *arg)
{
    long long prod = 1;

    for (int i = 0; i < 20; i++)
    {
        prod *= arr[i];
    }
    cout << "Product = " << prod << endl;
    return NULL;
}
void *array_search(void *arg)
{
    bool l = false;
    for (int i = 0; i < 20; i++)
    {
        if (arr[i] == key)
        {
            l = true;
            break;
        }
    }
    l ? cout << "Found key: " : cout << "Not Found key: ";
    cout << key << endl;
    return NULL;
}

int main()
{
    pthread_t thread[3];
    srand(time(NULL));
    key = rand()%100;
    for (int i = 0; i < 20; i++)
        arr[i] = i + 1;

    pthread_attr_t thread_attr;
    pthread_attr_init(&thread_attr);
    pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);

    pthread_create(&thread[0], &thread_attr, array_sum, NULL);
    pthread_create(&thread[1], &thread_attr, array_mul, NULL);
    pthread_create(&thread[2], &thread_attr, array_search, NULL);

    pthread_attr_destroy(&thread_attr);
    usleep(10000);
    return 0;
}