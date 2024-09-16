#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
using namespace std;
int a = 1, b = 2, c = 3, d = 4;
int main()
{

    int p1[2];

    if (pipe(p1) == -1)
        cout << "error in pipe \n";

    pid_t pid1 = fork();

    if (pid1 == 0)
    {
        int x = d * a;
        close(p1[0]);
        write(p1[1], &x, sizeof(x));
        close(p1[1]);
    }
    else if (pid1 > 0)
    {
        int x;
        close(p1[1]);
        if (read(p1[0], &x, sizeof(x)) <= 0)
            cout << "error in reading" << endl;
        close(p1[0]);


        int p2[2];

        if (pipe(p2) == -1)
            cout << "error in pipe \n";

        pid_t id = fork();

        if (id == 0)
        {
            close(p2[0]);
            int p3[2];
            if (pipe(p3) == -1)
                cout << "error in pipe \n";
            int x = a + b;
            int y;
            pid_t id2 = fork();
            if (id2 == 0)
            {
                int v = c - a;
                close(p3[0]);
                write(p3[1], &v, sizeof(int));
                close(p3[1]);
            }
            else
            {
                close(p3[1]);
                read(p3[0], &y, sizeof(int));

                close(p3[0]);
                int z = x + y;
              
                write(p2[1], &z, sizeof(int));
                close(p2[1]);
            }
        }
        else
        {
            int s;
            close(p2[1]);
            read(p2[0], &s, sizeof(int));
            close(p2[0]);
            close(p1[0]);
            close(p1[1]);
            cout << "The answer is " << s * x << endl;
        }
    }
    return 0;
}