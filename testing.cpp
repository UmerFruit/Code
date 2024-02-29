#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

/*
    A = (4*2) * [(2+3) + (4-2)]
    A = 8 * [5 + 2]
    A = 8 * 7
    A = 56
    A=(d*a) * [ (a+b) + (c-a) ]
    considering your roll num, you need to choose your last 4 characters and
    assign these 4 values to a b c and d (for example 19i-1234). a = 1 b =2 c =
    3 d=4.
    Write a program where root parent will be ‘A’. Parent will create first child
    which returns (d*a). Then parent will create second child. This child will
    calculate (a+b). Moreover, this child will create grandchild which will return

    (c-a). After receiving value from grandchild, this child will return [ (a+b) + (c-
    a) ] to the parent A. Parent A will display the end result of the equation.
*/

int child2(int a, int b, int c)
{
    int s1 = a + b;
    pid_t pid = fork();
    if (pid == 0)
    {
        exit(c - a);
    }
    else
    {
        int status = 0;
        waitpid(pid, &status, 0);
        int res = WEXITSTATUS(status);
        exit((a + b) + (c - a));
    }
}

int main()
{

    int a = 2, b = 3, c = 4, d = 4;
    pid_t pid[3];

    pid[0] = fork();

    if (pid[0] == 0)
    {
        exit(a*d);
    }
    else
    {
        int status = 0;
        waitpid(pid[0], &status, 0);

        int res1 = WEXITSTATUS(status);
        cout << "this is parent and recieved : " << res1 << endl;
        pid[1] = fork();
        if (pid[1] == 0)
        {
            exit(child2(a, b, c));
        }
        else
        {
            status = 0;
            waitpid(pid[1], &status, 0);

            int res2 = WEXITSTATUS(status);
            cout << "res2 = " << res2 << endl;
            cout << "res1 = " << res1 << endl;
            cout << "answer = " << res1 * res2 << endl;
        }
    }
    return 0;
}