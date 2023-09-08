#include "Headers.h"
using namespace std;
inline uint64_t gettime()
{
    uint64_t ms = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
    return ms;
}

int main()
{
    const int n = 10;
    int arr[n] ={9, 5, 2, 1, 6, 8, 7, 3, 4, 0};
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}