#include <iostream>
#include <pthread.h>
using namespace std;
void *threadprint(void *arg)
{
    // cout << "“" << pthread_self() << endl;
    printf("Hello I am thread and my ID is : %ld \n ", pthread_self());
    // cout << "Hello I am thread and my ID is : " << reinterpret_cast<long>(pthread_self()) << endl;
}
int main()
{
    int n;
    cout << "Enter number" << endl;
    cin >> n;
    pthread_t *threads = new pthread_t[n];
    for (int i = 0; i < n; i++)
    {
        pthread_create(&threads[i], NULL, threadprint, NULL);
    }
    for (int i = 0; i < n; i++)
    {
        pthread_join(threads[i], NULL);
    }
}