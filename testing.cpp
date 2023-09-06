#include "Headers.h"
using namespace std;
int main()
{
    int arr[10] = {6,8,3,1,2,4,9,5,7,0};
    int size = 10;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
        
    }
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }   
    
}