#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
using namespace std;

int main()
{
    char command[10];

    while (1)
    {
        bool Exit = false;
        cout << "Enter a command (or 'Exit' to quit): ";
        cin.getline(command, 10);
        command[strcspn(command, "\n")] = 0; // Remove trailing newline

        if (strcmp(command, "Exit") == 0)
        {
            cout << "Exiting program...\n";
            Exit = true;
            break;
        }
        pid_t pid = fork();
        if (pid < 0)
        {
            cerr<<"fork failed\n";
            break;
        }
        else if (pid == 0)
        { // Child process
            if (strcmp(command, "ls") == 0)
            {
                execl("/bin/ls", "ls", nullptr);
                cerr<<"exec failed\n";
                exit(EXIT_FAILURE);
            }
            else if (strcmp(command, "touch") == 0)
            {
                string name;
                cout<<"Enter file name: ";
                cin>>name;
                execlp("touch", "touch", (char*)name.c_str(), nullptr);
                cerr<<"exec failed\n";
                exit(EXIT_FAILURE);
            }
            else if (strcmp(command, "date") == 0)
            {
                char* args[] = {"date", nullptr};
                execv("/bin/date", args);
                cerr<<"exec failed\n";
                exit(EXIT_FAILURE);
            }
            else if (strcmp(command, "pwd") == 0)
            {
                char* args[] = {"pwd", nullptr};
                execvp("pwd", args);
                cerr<<"exec failed\n";
                exit(EXIT_FAILURE);
            }
            else
            {
                cout<<"Invalid command\n";
            }
        }
        else
        { // Parent process
            int status;
            waitpid(pid, &status, 0);
        }
        if(Exit)
        {
            exit(0);
        }
    }

    return 0;
}
