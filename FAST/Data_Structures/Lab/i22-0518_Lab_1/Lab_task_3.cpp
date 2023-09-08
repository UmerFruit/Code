#include <iostream>
using namespace std;

bool BinSearch(int *arr, int size, int find)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        int middle = start + (end - start) / 2;
        if (arr[middle] == find)
        {
            return true;
        }
        else if (arr[middle] < find)
        {
            start = ++middle;
        }
        else
        {
            end = --middle;
        }
    }

    return false;
}

int main()
{
    int find = 2;
    int row = 3;
    int col = 4;
    int arr[3][4] = {{12, 43, 66, 78},
                     {34, 21, 72, 81},
                     {7, 13, 2, 59}};

    int size = row * col;
    int *A = new int[size];
    int c = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            A[c++] = arr[i][j];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (A[i] < A[j])
                swap(A[i],A[j]);

    if(BinSearch(A,size,find))
    {
        cout<<"FOUND!\n";
    }
    else
    {
        cout<<"NOT FOUND!\n";
    }
    

}
