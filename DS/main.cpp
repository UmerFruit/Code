#include "Headers.h"
float totalTime(vector<VM> &v)
{
    float sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i].timeTaken();
    }
    return sum;
}
void allocate(Job &j, vector<VM> &vms)
{
    int lowestperc = 100, maxcap = 0, idx = -1;
    for (int i = 0; i < vms.size(); i++)
    {
        if (vms[i].compPower > maxcap && vms[i].percUsed < lowestperc && vms[i].currentJobs < vms[i].maxJobs)
        {
            idx = i;
        }
    }
    if (idx == -1)
    {
        VM temp(rand() % 10000 + 1000);
        temp.jobsheap.insert(j);
        temp.currentJobs++;
        temp.percUsed = (static_cast<float>(temp.currentJobs) / temp.maxJobs) * 100;
        vms.push_back(temp);
        return;
    }
    else if (vms[idx].compPower > j.compReqs)
    {
        vms[idx].jobsheap.insert(j);
        vms[idx].currentJobs++;
        vms[idx].percUsed = (static_cast<float>(vms[idx].currentJobs) / vms[idx].maxJobs) * 100;
    }
    else
    {
        j.compReqs -= vms[idx].compPower;
        if (j.compReqs < vms[idx].compPower)
        {
            vms[idx].currentJobs++;
            vms[idx].percUsed = (static_cast<float>(vms[idx].currentJobs) / vms[idx].maxJobs) * 100;
        }

        VM temp(rand() % 10000 + 1000);
        temp.jobsheap.insert(j);
        temp.currentJobs++;
        temp.percUsed = (static_cast<float>(temp.currentJobs) / temp.maxJobs) * 100;
        vms.push_back(temp);
    }
}
void recovery(vector<VM> &v)
{
    ifstream fin("FailedJobs.txt");
    int compReqs, priority;
    string name;
    int i = 1;
    while (!fin.eof())
    {
        fin >> name >> compReqs >> priority;
        Job *j = new Job(name, compReqs, priority);
        allocate(*j, v);
    }
    fin.close();
    remove("FailedJobs.txt");
}
int main()
{
    int n;
    cout << "Input number of Jobs to be completed: " << endl;
    cin >> n;
    srand(time(0));
    MaxHeap jobs(n);
    int compReqs, priority;
    for (int i = 1; i <= n; i++)
    {
        string name = "Job" + to_string(i);
        compReqs = rand() % 250 * 10 + 1;
        priority = rand() % 100 + 1;
        Job *j = new Job(name, compReqs, priority);
        jobs.insert(*j);
    }
    vector<VM> vms;
    VM temp(rand() % 1000 + 100);

    vms.push_back(temp);
    for (int i = 1; i <= n; i++)
    {
        Job j = jobs.deleteHeap();
        allocate(j, vms);
        if (!(rand() % 100))
        {
            int x = rand() % vms.size();
            cout << "\n\nHandling Failure of VM num: " << x + 1 << endl;
            vms[x].handleFailure();
            vms.erase(vms.begin() + x);
            recovery(vms);
            cout << "Recovery Done. Reallocation of Jobs successful\n\n";
        }
    }
    for (int i = 0; i < vms.size(); i++)
    {
        vms[i].showSummary();
        cout << endl;
    }
    cout << "Number of VMS used: " << VM::numVMs << "\nFailed: " << VM::failed << endl;
    cout << "Total time taken: " << totalTime(vms) << " Milliseconds, To complete " << n << " Jobs" << endl;
}
