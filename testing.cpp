#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    int p1[2]; // C => P
    int p2[2]; // P => C
    if (pipe(p1) == -1)
        return 1;
    if (pipe(p2) == -1)
        return 1;
    pid_t pid = fork();
    if (pid == -1)
        return 2;
    else if (pid == 0)
    {
        close(p1[0]);
        close(p2[1]);

        string x;
        read(p2[0], &x, sizeof(x));
        cout << "Child: " << x << endl;
        vector<string> v= {"umer", "ali", "ahmed", "khan", "Jamaal", "maleek", "saif", "humayun", "arsalan", "ash"};
        for (int i = 0; i < 10; i++)
        {
            write(p1[1], &v[i], sizeof(string));
        }
        

        close(p2[0]);
        close(p1[1]);
    }
    else
    {
        close(p2[0]);
        close(p1[1]);

        string y = "Hello umer";
        write(p2[1], &y, sizeof(y));
        cout << "Wrote from Parent: " << y << endl;
        vector<string> rec(10);
        for (int i = 0; i < 10; i++)
        {
            read(p1[0], &rec[i], sizeof(string));
        }
        
        
        cout << "Parent: " << y << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << rec[i] << " ";
        }
        cout << endl;

        close(p2[1]);
        close(p1[0]);
    }

    return 0;
}
