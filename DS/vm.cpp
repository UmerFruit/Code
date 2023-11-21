#include <iostream>
#include 
using namespace std;

class Job
{
public:
    string name;
    int compReqs;
    int priorityLevel;

    Job(string n, int compRequirements, int priority)
    {
        this->name = name;
        compReqs = compRequirements;
        priorityLevel = priority;
    }
};

class VM
{
private:
    int maxNumberJobs;

    int computingCapacity;
    float percentageUsed;

    int maxJobsPerVM;
    int currentJobs;

    int jobsCompleted;

    Job *j;

public:
    VM(int capacity)
    {
        computingCapacity = capacity;
    }

    VM()
    {
        computingCapacity = 0;
        percentageUsed = 0;
    }

    void allocateJob(Job newJob)
    {
    }

    void handleFailure()
    {
    }

    void showSummary()
    {
        // time etc will be local variables
    }
};
