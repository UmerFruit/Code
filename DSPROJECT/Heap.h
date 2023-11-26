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
            int leftChild = 2 * i;
            int rightChild = (2 * i) + 1;
            int largest = i;

            if (leftChild <= numelements && arr[largest] < arr[leftChild])
            {
                largest = leftChild;
            }

            if (rightChild <= numelements && arr[largest] < arr[rightChild])
            {
                largest = rightChild;
            }

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

// class MinHeap
// {
// public:
//     Job *arr; // dynamic array
//     int numelements;

//     MaxHeap(int arrsize)
//     {
//         arr = new Job[++arrsize];
//         numelements = 0;
//     }

//     void insert(Job val)
//     {
//         int index = ++numelements;
//         arr[index] = val;

//         while (index > 1)
//         {
//             int parent = index / 2;

//             if (arr[parent].priorityLevel < arr[index].priorityLevel)
//             {
//                 swap(arr[parent], arr[index]);
//                 index = parent;
//             }
//             else
//             {
//                 return;
//             }
//         }
//     }

//     Job deleteHeap()
//     {
//         if (numelements == 0)
//         {
//             cout << "Heap is empty!" << endl;
//         }
//         else
//         {
//             Job temp = arr[1];

//             arr[1] = arr[numelements];
//             numelements--;

//             int i = 1;
//             while (i < numelements)
//             {
//                 int leftChild = 2 * i;
//                 int rightChild = (2 * i) + 1;
//                 int largest = i;

//                 if (leftChild <= numelements && arr[largest].priorityLevel < arr[leftChild].priorityLevel)
//                 {
//                     largest = leftChild;
//                 }

//                 if (rightChild <= numelements && arr[largest].priorityLevel < arr[rightChild].priorityLevel)
//                 {
//                     largest = rightChild;
//                 }

//                 if (largest == i)
//                 {
//                     break;
//                 }
//                 else
//                 {
//                     swap(arr[i], arr[largest]);
//                     i = largest;
//                 }
//             }
//             return temp;
//         }
//     }
//     void heapify(int *arr, int n, int i)
//     {
//         int smallest = i;
//         int left = 2 * i + 1;
//         int right = 2 * i + 2;

//         if (left < n && arr[smallest] > arr[left])
//         {
//             smallest = left;
//         }

//         if (right < n && arr[smallest] > arr[right])
//         {
//             smallest = right;
//         }

//         if (smallest != i)
//         {
//             swap(arr[i], arr[smallest]);
//             heapify(arr, n, smallest);
//         }
//     }
//     void print()
//     {
//         cout << "Max Heap : ";
//         for (int i = 0; i < numelements; i++)
//         {
//             cout << arr[i + 1];
//         }
//         cout << endl;
//     }
// };

#endif /* HEAP_H_ */