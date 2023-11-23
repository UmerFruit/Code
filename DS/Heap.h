#ifndef HEAP_H_
#define HEAP_H_
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
        cout << "Name : " << name << endl;
        cout << "Comp Reqs : " << compReqs << endl;
        cout << "Priority Level : " << priorityLevel << endl;
    }
    friend ostream &operator<<(ostream &os, Job &right)
    {
        cout << "Name : " << right.name << endl
             << "Comp Reqs : " << right.compReqs << endl
             << "Priority Level : " << right.priorityLevel << endl;

        return os;
    }
};

class MaxHeap
{
public:
    Job *arr; // dynamic array
    int size;

    MaxHeap(int arrsize)
    {
        arr = new Job[arrsize];
        size = 0;
    }

    void insert(Job &val)
    {
        int index = ++size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent].priorityLevel < arr[index].priorityLevel)
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

    Job &deleteHeap()
    {
        if (size == 0)
        {
            cout << "Heap is empty!" << endl;
        }
        else
        {
            Job &temp = arr[1];

            arr[1] = arr[size];
            size--;

            int i = 1;
            while (i < size)
            {
                int leftChild = 2 * i;
                int rightChild = (2 * i) + 1;
                int largest = i;

                if (leftChild <= size && arr[largest].priorityLevel < arr[leftChild].priorityLevel)
                {
                    largest = leftChild;
                }

                if (rightChild <= size && arr[largest].priorityLevel < arr[rightChild].priorityLevel)
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
            return temp;
        }
    }

    void print()
    {
        cout << "Max Heap : ";
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i];
        }
        cout << endl;
    }
};

class VM
{
public:
    int maxJobs;
    int compPower;
    float percUsed;
    int currentJobs;
    int jobsCompleted;
    MaxHeap jobsheap;

public:
    VM(int compP = 1000, int capacity = 10) : jobsheap(capacity)
    {
        maxJobs = capacity;
        compPower = compP;
        currentJobs = 0;
        percUsed = 0;
        jobsCompleted = 0;
    }

    void handleFailure()
    {
        // write all jobs to file
        ofstream fout("completedJobs.txt");
        for (int i = 0; i < currentJobs; i++)
        {
            fout << jobsheap.arr[i];
        }
        fout.close();
        // delete VM
    }
    void showSummary()
    {
        cout << "VM Summary : " << endl;
        cout << "Max Jobs : " << maxJobs << endl;
        cout << "Comp Power : " << compPower << endl;
        cout << "Current Jobs : " << currentJobs << endl;
        cout << "Jobs Completed : " << jobsCompleted << endl;
        cout << "Percentage Used : " << percUsed << endl;

        // time etc will be local variables
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
#endif /* HEAP_H_ */