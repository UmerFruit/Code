#include <iostream>
#include "Heap.cpp"
using namespace std;

class VM
{
public:
    int maxJobs;
    int compPower;
    float percUsed;
    int currentJobs;
    int jobsCompleted;
    MaxHeap j;
public:
    VM(int compP,int capacity = 10)
    {
        maxJobs = capacity;
        compPower = compP;
        currentJobs = 0;
        percUsed = 0;
        jobsCompleted = 0;
    }
    void allocateJob(Job newJob)
    {
        if(currentJobs == maxJobs)
        {
            cout<<"VM is full!"<<endl;
            return;
        }
        j.insert(newJob,);
        currentJobs++;
        percUsed = (float)currentJobs/maxJobs;
    }
    void handleFailure()
    {
    }
    void showSummary()
    {
        // time etc will be local variables
    }
};
