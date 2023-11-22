#include <iostream>
using namespace std;
class Job
{
public:
    string name;
    int compReqs;
    int priorityLevel;
    Job(string n = "No Name", int c = 0, int p = 0)
    {
        name = n;
        compReqs = c;
        priorityLevel = p;
    }
    void print()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Comp Reqs : "<<compReqs<<endl;
        cout<<"Priority Level : "<<priorityLevel<<endl;
    }
};
class MinHeap
{
public:
    int arr[100];
    int size;

    MinHeap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        int index = ++size;
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

    void deleteHeap()
    {
        if (size == 0)
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int leftChild = 2 * i;
            int rightChild = (2 * i) + 1;
            int largest = i;

            if (leftChild <= size && arr[largest] > arr[leftChild])
            {
                largest = leftChild;
            }

            if (rightChild <= size && arr[largest] > arr[rightChild])
            {
                largest = rightChild;
            }

            if (largest == i)
            {
                return;
            }
            else
            {
                swap(arr[i], arr[largest]);
                i = largest;
            }
        }
    }

    void print()
    {
        cout << "Min Heap : ";
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
class MaxHeap
{
public:
    int arr[100];
    int size;

    MaxHeap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        int index = ++size;
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

    void deleteHeap()
    {
        if (size == 0)
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int leftChild = 2 * i;
            int rightChild = (2 * i) + 1;
            int largest = i;

            if (leftChild <= size && arr[largest] < arr[leftChild])
            {
                largest = leftChild;
            }

            if (rightChild <= size && arr[largest] < arr[rightChild])
            {
                largest = rightChild;
            }

            if (largest == i)
            {
                return;
            }
            else
            {
                swap(arr[i], arr[largest]);
                i = largest;
            }
        }
    }

    void print()
    {
        cout << "Max Heap : ";
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
