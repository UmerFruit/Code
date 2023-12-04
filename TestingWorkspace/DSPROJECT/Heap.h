#ifndef HEAP_H_
#define HEAP_H_
#include <vector>
using namespace std;
template <class T>
class MaxHeap
{
    vector<T> arr;
    int maxsize;
    int numelements;

public:
    MaxHeap(int arrsize)
    {
        maxsize = arrsize;
        arr.resize(++arrsize);
        numelements = 0;
    }
    T max()
    {
        return arr[1];
    }
    int size()
    {
        return numelements;
    }
    void Push(T val)
    {
        if (numelements == maxsize)
        {
            cout << "Heap is full!" << endl;
            return;
        }
        int index = ++numelements;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void Pop()
    {
        if (numelements == 0)
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        T temp = arr[1];
        arr[1] = arr[numelements];
        numelements--;

        int i = 1;
        while (i < numelements)
        {
            int LC = 2 * i;
            int RC = (2 * i) + 1;
            int largest = i;

            if (LC <= numelements && arr[largest] < arr[LC])
                largest = LC;

            if (RC <= numelements && arr[largest] < arr[RC])
                largest = RC;

            if (largest == i)
            {
                break;
            }
            else
            {
                swap(arr[i], arr[largest]);
                i = largest;
            }
        }
    }
    void display()
    {
        for (int i = 0; i < numelements; i++)
        {
            cout << arr[i + 1] << " ";
        }
        cout << endl;
    }
};

template <class T>
class MinHeap
{
    vector<T> arr;
    int maxsize;
    int numelements;

public:
    MinHeap(int arrsize)
    {
        maxsize = arrsize;
        arr.resize(++arrsize);
        numelements = 0;
    }
    T min()
    {
        return arr[1];
    }
    int size()
    {
        return numelements;
    }
    void Push(T val)
    {
        if (numelements == maxsize)
        {
            cout << "Heap is full!" << endl;
            return;
        }
        int index = ++numelements;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] > arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void Pop()
    {
        if (numelements == 0)
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        T temp = arr[1];
        arr[1] = arr[numelements];
        numelements--;

        int i = 1;
        while (i < numelements)
        {
            int LC = 2 * i;
            int RC = (2 * i) + 1;
            int largest = i;

            if (LC <= numelements && arr[largest] > arr[LC])
                largest = LC;

            if (RC <= numelements && arr[largest] > arr[RC])
                largest = RC;

            if (largest == i)
            {
                break;
            }
            else
            {
                swap(arr[i], arr[largest]);
                i = largest;
            }
        }
    }
    void display()
    {
        for (int i = 0; i < numelements; i++)
        {
            cout << arr[i + 1] << " ";
        }
        cout << endl;
    }
};

#endif /* HEAP_H_ */