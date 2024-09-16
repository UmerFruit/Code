#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
#include <map>
using namespace std;
void countVotes(int *arr, int n = 10)
{
    int counter[3] = {0};
    int candidate = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            counter[0]++;
        else if (arr[i] == 1)
            counter[1]++;
        else
            counter[2]++;
    }
    int max = counter[0];
    int idx = 0;
    char a[4] = "ABC";
    for (int i = 0; i < 3; i++)
    {
        cout << "Candidate " << a[i] << " got " << counter[i] << endl;
        if (counter[i] > max)
        {
            max = counter[i];
            idx = i;
        }
    }
    cout << "Winner is " << a[idx] << " with " << counter[idx] << " votes." << endl;
}
int main()
{

    int n;
    cout << "Enter number of voters: ";
    cin >> n;
    int p1[2];

    int *count = new int[n];
    for (int i = 0; i < n; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
    {
        if (pipe(p1) == -1)
            cout << "error in pipe \n";

        pid_t pid = fork();
        int val;
        if (pid == 0)
        {
            srand(time(NULL) + getpid());
            int x = rand() % 3;
            close(p1[0]);
            write(p1[1], &x, sizeof(x));
            close(p1[1]);

            return 0;
        }
        else
        {
            wait(NULL);
            close(p1[1]);
            read(p1[0], &count[i], sizeof(val));
            close(p1[0]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << count[i] << " ";
    }
    cout << endl;
    countVotes(count, n);
    return 0;
}