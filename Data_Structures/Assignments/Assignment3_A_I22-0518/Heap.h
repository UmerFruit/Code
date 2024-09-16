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
    Job(string n = "NoName", int c = 0, int p = 0)
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
    friend ofstream &operator<<(ofstream &os, Job &right)
    {
        os << right.name << endl
           << right.compReqs << endl
           << right.priorityLevel << endl;

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
        arr = new Job[++arrsize];
        size = 0;
    }

    void insert(Job val)
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

    Job deleteHeap()
    {
        if (size == 0)
        {
            cout << "Heap is empty!" << endl;
        }
        else
        {
            Job temp = arr[1];

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
        for (int i = 0; i < size; i++)
        {
            cout << arr[i + 1];
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
    static int numVMs,failed;
    MaxHeap jobsheap;

public:
    VM(int compP = 1000, int capacity = 10) : jobsheap(capacity)
    {
        numVMs++;
        maxJobs = capacity;
        compPower = compP;
        currentJobs = 0;
        percUsed = 0;
        jobsCompleted = 0;
    }
    float timeTaken()
    {
        // time taken to complete all jobs
        int reqsum = 0;
        for (int i = 1; i < jobsheap.size; i++)
        {
            reqsum += jobsheap.arr[i].compReqs;
        }
        float time = reqsum / static_cast<float>(compPower);
        return time;
    }
    void handleFailure()
    {
        failed++;
        
        ofstream fout("FailedJobs.txt");
        for (int i = 1; i < maxJobs; i++)
        {
            fout << jobsheap.arr[i];
        }
        fout.close();
    }
    
    void showSummary()
    {
        cout << "VM Summary : " << endl;
        cout << "Max Jobs : " << maxJobs << endl;
        cout << "Comp Power : " << compPower << endl;
        cout << "Completed Jobs : " << currentJobs << endl;
        cout << "Percentage Used : " << percUsed << endl;
        cout << "Time taken to complete all jobs : " << timeTaken() << " Milliseconds" << endl;
    }
};
int VM::numVMs = 0;
int VM::failed = 0;
#endif /* HEAP_H_ */