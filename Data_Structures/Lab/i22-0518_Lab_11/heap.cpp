#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
class heap
{
public:
    int *arr;
    int capacity;
    int elements;

    heap(int capacity = 100)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        arr[0] = -1; // 1 based indexing
        elements = 0;
    }
    void insert(int val)
    {
        elements++;
        if (capacity == elements)
        {
            cout << "Heap is full." << endl;
            elements--;
            return;
        }
        arr[elements] = val;
        heapify();
    }
    void heapify()
    {
        int idx = elements;
        while (idx > 1)
        {
            int parent = idx / 2;
            if (arr[parent] < arr[idx])
            {
                swap(arr[parent], arr[idx]);
                idx = parent;
            }
            else
                return;
        }
    }
    int remove()
    {
        if (elements == 0)
        {
            cout << "Heap is empty." << endl;
            return -1;
        }
        int val = arr[1];
        arr[1] = arr[elements];
        elements--;
        int idx = 1;
        while (idx < elements)
        {
            int left = 2 * idx;
            int right = 2 * idx + 1;
            if (left > elements)
                return val;
            if (right > elements)
            {
                if (arr[left] > arr[idx])
                {
                    swap(arr[left], arr[idx]);
                    idx = left;
                }
                else
                    return val;
            }
            else
            {
                if (arr[left] > arr[right])
                {
                    if (arr[left] > arr[idx])
                    {
                        swap(arr[left], arr[idx]);
                        idx = left;
                    }
                    else
                        return val;
                }
                else
                {
                    if (arr[right] > arr[idx])
                    {
                        swap(arr[right], arr[idx]);
                        idx = right;
                    }
                    else
                        return val;
                }
            }
        }
        return val;
    }
    bool isEmpty()
    {
        return elements == 0;
    }
    void clear()
    {
        delete[] arr;
        elements = 0;
        arr = new int[capacity];
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
