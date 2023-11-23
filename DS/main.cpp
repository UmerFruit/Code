#include "Headers.h"
/*
    har vm ki apni maxheap which sotres theamount of jobs based on priority.
    jobs assign hone k baad vo heap se delete hojayegi.
    assign honay ka matlab hai vo ek "completed" ki queue mai push hojaya gi
    vms in minheap according to perc-used
    queue mai saare jobs read hogaye, phir uske baad vm mai allocate hogaye
    heap bharti jaaye gi vo dequeue hokar
    check if the available comp power is enough to handle the job
    if not spawn new
    if yes then check if perc used is less than 80%
    if yes then allocate
    if no then spawn new
    jese hi uski max jobs hit hogayi
    uski saari jobs write kardo file mai (completed queue mai jo hain),
    har job ki comp req ko nano seconds ke mutabik likhdo, aur vm delete kardo
    jab tak queue mai kuch hai tab tak chalega
*/
bool possible(Job newJob, vector<VM> &v)
{

    int i = 0;
    while (i < v.size())
    {
        if (v[i].percUsed < 80)
        {
            if (v[i].compPower >= newJob.compReqs)
            {
                if (v[i].compPower <= 0)
                {
                    return true;
                }

            }
        }
        i++;
    }
}
void allocateJob(Job newJob, vector<VM> &v)
{
    int i = 0;
    while (i < v.size())
    {
        if (v[i].percUsed < 80)
        {
            if (v[i].compPower >= newJob.compReqs)
            {
                v[i].compPower -= newJob.compReqs;
                if (v[i].compPower == 0 || v[i].compPower < 0)
                {
                    v[i].compPower += newJob.compReqs;
                    VM newVM(newJob.compReqs * 2, 10);
                    v.push_back(newVM);
                    break;
                }
                v[i].jobsheap.insert(newJob);
                v[i].currentJobs++;
                v[i].percUsed = (v[i].currentJobs * 100) / v[i].maxJobs;
                return;
            }
        }
        i++;
    }
}
int main()
{
    // Job j1("Job1", 10, 1);
    // Job j2("Job2", 20, 2);
    // Job j3("Job3", 30, 3);
    // Job j4("Job4", 40, 4);
    // Job j5("Job5", 50, 5);

    // Job j6("Job6", 60, 6);
    // Job j7("Job7", 70, 7);
    // Job j8("Job8", 80, 8);
    // Job jobs[] = {j1, j2, j3, j4, j5, j6, j7, j8};
    // MaxHeap jobsHeap(8);
    int n = 10;
    MaxHeap jobs(n);
    for (int i = 1; i <= n; i++)
    {
        string name = "Job" + to_string(i);
        int compReqs = i * 100;
        int priority = i;
        Job j(name, compReqs, priority);
        jobs.insert(j);
    }
    jobs.print();
    cout << "\n\n\n\n\n";
    vector<VM> vms;
    vms.push_back(VM(1000, 10));
    for (int i = 1; i <= n; i++)
        allocateJob(jobs.deleteHeap(), vms);

    for (int i = 0; i < vms.size(); i++)
    {
        cout << endl;

        vms[i].jobsheap.print();
        cout << endl;
        vms[i].showSummary();
        cout << endl;
    }
}
