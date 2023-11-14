#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
class heap
{
public:
    int *arr;
    int elements;

    heap(int capacity = 100)
    {
        arr = new int[capacity];
        arr[0] = -1; // 1 based indexing
        elements = 0;
    }
    void insert(int val)
    {
        elements++;
        int idx = elements;
        arr[idx] = val;
        while (idx > 1)
        {
            int parent = idx / 2;
            if (arr[parent] > arr[idx])
            {
                swap(arr[parent], arr[idx]);
                idx = parent;
            }
            else
                return;
        }
    }
    void deleteMin()
    {
        if (elements == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }
        arr[1] = arr[elements];
        elements--;
        int i = 1;
        while (i < elements)
        {
            int right = 2 * i + 1;
            int left = 2 * i;

            if (left < elements && arr[i] > arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }
            else if (right < elements && arr[i] > arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else
            {
                return;
            }
        }
    }
    ~heap()
    {
        delete[] arr;
    }
    void print()
    {
        for (int i = 1; i <= elements; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


