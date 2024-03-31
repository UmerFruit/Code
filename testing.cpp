#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
// A=(d*a) * [ (a+b) + (c-a) ]
// considering your roll num, you need to choose your last 4 characters and
// assign these 4 values to a b c and d (for example 19i-1234). a = 1 b =2 c =
// 3 d=4.
// Write a program where root parent will be ‘A’. Parent will create first child
// which returns (d*a). Then parent will create second child. This child will
// calculate (a+b). Moreover, this child will create grandchild which will return
// (c-a). After receiving value from grandchild, this child will return [ (a+b) + (c-
// a) ] to the parent A. Parent A will display the end result of the equation.
int main()
{
    int a = 1, b = 9, c = 1, d = 2;
    int fd1[2], fd2[2];
    pipe(fd1);
    pipe(fd2);
    int pid1 = fork(); 
    if (!pid1)
    {
        // Child 1
        close(fd1[0]);
        int result = d * a;
        write(fd1[1], &result, sizeof(result));
        close(fd1[1]);
    }
    else
    {
        int pid2 = fork();
        if (pid2 == 0)
        {
            // Child 2
            close(fd1[1]);
            int result1;
            read(fd1[0], &result1, sizeof(result1));
            close(fd1[0]);
            int result2 = a + b;
            int pid3 = fork();
            if (pid3 == 0)
            {
                // Grandchild
                int result3 = c - a;
                close(fd2[0]);
                write(fd2[1], &result3, sizeof(result3));
                close(fd2[1]);
            }
            else
            {
                wait(NULL);
                int result3;
                close (fd2[1]);
                read(fd2[0], &result3, sizeof(result3));
                close(fd2[0]);
                int final_result = result2 + result3;
                close(fd1[0]);
                write(fd1[1], &final_result, sizeof(final_result));
                close(fd1[1]);
            }
        }
        else
        {
            wait(NULL);
            int result;
            read(fd1[0], &result, sizeof(result));
            close(fd1[0]);
            cout << "Result: " << result << endl;
        }
    }
    return 0;
}