#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
#include <map>
using namespace std;
int mostFrequent(int *arr, int n = 10)
{
    int maxcount = 0;
    int maxfreq;
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        for (int j = 0; j < n; j++)
            if (arr[i] == arr[j])
                c++;

        if (c > maxcount)
        {
            maxcount = c;
            maxfreq = arr[i];
        }
    }

    return maxfreq;
}
int main()
{

    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    // n = 11;
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
            int x = rand() % 10;
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
        cout << count[i] << " ";

    cout << endl;
    cout << "Most guessed number is: " << mostFrequent(count,n) << endl;
    return 0;
}