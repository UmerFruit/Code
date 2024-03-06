#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main()
{
    int choice;
    bool leave = false;
    while (true)
    {
        cout << " Menu " << endl;
        cout << "1. ls " << endl;
        cout << "2. mv " << endl;
        cout << "3. cp " << endl;
        cout << "4. echo " << endl;
        cout << "5. clear " << endl;
        cout << "6. Hello World! " << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        pid_t pid = fork();
        
        if (pid < 0)
        {
            cout << "Error " << endl;
            exit(1);
        }
        else if (pid == 0)
        {
            if (choice == 1)
            {
                execl("/bin/ls", "ls", NULL);
                cout << "Error " << endl;
                exit(1);
            }
            else if (choice == 2)
            {
                execl("/bin/mv", "mv", NULL);
                cout << "Error " << endl;
                exit(2);
            }
            else if (choice == 3)
            {
                execlp("cp", "cp", NULL);
                cout << "Error " << endl;
                exit(3);
            }
            else if (choice == 4)
            {
                string str;
                cout<<"Enter string to echo:";
                cin>>str;
                execl("/bin/echo", "echo",str.c_str(), NULL);
                cout << "Error " << endl;
                exit(4);
            }
            else if (choice == 5)
            {
                execlp("clear", "clear", NULL);
                cout << "Error " << endl;
                exit(5);
            }
            else if (choice == 6)
            {
                execlp("./h", "./h", NULL);
                cout << "Error " << endl;
                exit(6);
            }
            else if (choice == 7)
            {
                leave = true;
                exit(7);
            }
            else
            {
                cout << "Invalid choice.\n";
            }
        }
        else
        {
            wait(NULL);
        }
        if (leave)
        {
            exit(0);
        }
    }

    return 0;
}