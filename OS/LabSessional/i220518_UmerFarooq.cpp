#include <stdio.h>
#include <pthread.h>
#include <iostream>
using namespace std;
int arr[20] = {0};
int n,rem;
int counter = 0;
void *fun(void *a)
{
    long long *prod = new long long;
    *prod = 1;
    for (int i = 0; i < 20 / n && counter < 20; counter++, i++)
    {
        *prod *= arr[counter];
    }
    pthread_exit((void *)prod);
    // 20! = 2432902008176640000
}
int main()
{
    for (int i = 0; i < 20; i++)
        arr[i] = i + 1; // fill

    cout << "Enter number of threads(only 1,2,4,5,20 i.e factors): ";
    cin >> n;
    pthread_t *tid = new pthread_t[n];
    for (int i = 0; i < n; i++)
    {
        pthread_create(&tid[i], 0, fun, 0);
    }
    void *status[n];
    long long l1[n];
    long long finprod=1;
    for (int i = 0; i < n; i++)
    {
        pthread_join(tid[i], &status[i]);
        l1[i] = *((long long *)status[i]);
        finprod *= l1[i];
        cout<<"Recieved "<<i<<" : "<<l1[i]<<endl;
    }
    cout<<"Final prod = "<<finprod<<endl;
    
}