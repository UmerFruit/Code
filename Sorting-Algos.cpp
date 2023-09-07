#include "Headers.h"
using namespace std;
inline uint64_t gettime()
{
    uint64_t ms = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
    return ms;
}
void randomize(int *arr, long long size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10;
    }
}
uint64_t BubbleSort(int *arr, long long size)
{
    int temp;
    uint64_t ms1 = gettime();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j + 1] = arr[size - 1 - i];
                arr[size - 1 - i] = temp;
            }
        }
    }
    uint64_t ms2 = gettime();
    return ms2 - ms1;
}
uint64_t SelectionSort(int *arr, long long size)
{
    int temp;
    uint64_t ms1 = gettime();
    for (int i = 0; i < size; i++)
    {
        int max = arr[0], midx = 0;
        for (int j = 0; j < size - i; j++)
        {
            if (max < arr[j])
            {
                midx = j;
                max = arr[j];
            }
        }
        temp = arr[midx];
        arr[midx] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
    uint64_t ms2 = gettime();
    return ms2 - ms1;
}
uint64_t InsertionSort(int *arr, long long size)
{
    uint64_t ms1 = gettime();
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
    uint64_t ms2 = gettime();
    return ms2 - ms1;
}
int main()
{
    const int size = 10;
    int arr[size] = {9, 5, 2, 1, 6, 8, 7, 3, 4, 0};

    const long long size2 = 100000;
    int arr2[size2];

    randomize(arr2, size2);
    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    cout << "Time Taken For Insertion Sort: " << InsertionSort(arr2, size2) << endl;
    randomize(arr2, size2);
    cout << "Time Taken For Selection Sort: " << SelectionSort(arr2, size2) << endl;
    randomize(arr2, size2);
    cout << "Time Taken For Bubble Sort: " << BubbleSort(arr2, size2) << endl;
}