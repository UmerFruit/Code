#include <iostream>
using namespace std;
void reverse(int array[], int arr_length)
{
    for (int i = 0; i <= arr_length / 2; i++)
    {
        int temp = array[i];
        array[i] = array[arr_length - 1 - i] ;
        array[arr_length - 1 - i]  = temp;
    }

    for (int i = 0; i < arr_length; i++)
    {
        cout << array[i] << " ";
    }
}
int main()
{
    int *arr = new int[20];
    for (int i = 0; i < 20; i++)
    {
        *(arr + i) = i;
    }
    reverse(arr, 20);
}