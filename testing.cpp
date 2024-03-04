#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        cerr << "Fork failed" << endl;
        return 1;
    }
    else if (pid == 0)
    { // Child process
        // Take user input
        string inp = " ";
        // while(inp != "Exit")
        // {
        cout << "Enter Command: ";
        cin >> inp;
        // }
        
        cout<<"Enter arguments: "<<endl;
        cin>>
        execlp("ls", "ls", "-l", "/", NULL);
        cerr << "Exec failed" << endl;
        return 1;
    }
    else
    {               // Parent process
        wait(NULL); // Wait for the child to finish
        cout << "Child process completed" << endl;
    }

    return 0;
}