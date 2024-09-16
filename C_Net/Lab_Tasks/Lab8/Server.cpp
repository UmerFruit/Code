#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <iostream>
#include <string>
using namespace std;
void clear(char t[], int size = 256)
{
    for (int i = 0; i < 256; i++)
        t[i] = 0;
}
int main()
{

    char s_msg[256] = "Hi, Yes you have reached the server!";
    char buf[256];
    // create the server socket
    int s_sock = socket(AF_INET, SOCK_STREAM, 0);

    // define the server address
    sockaddr_in s_addr;
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(3001);
    s_addr.sin_addr.s_addr = INADDR_ANY;

    // bind the socket to our specified IP and port
    bind(s_sock, (sockaddr *)&s_addr, sizeof(s_addr));

    while (1)
    {
        listen(s_sock, 5);

        // Accept the next client connection
        int c_sock = accept(s_sock, NULL, NULL);
        pid_t id = fork(); // create a new process to handle the request
        string menu = "Menu 1. Concatenate two strings\n 2. Find the first occurrence of a character in a string \n3. Compares two string \n4. Checks whether string is palindrome or not\n5. String Number Addition \n6. exit";
        if (id == 0)
        {
            cout << "Menu" << endl;
            cout << "1. Concatenate two strings" << endl
                 << "2. Find the first occurrence of a character in a string" << endl
                 << "3. Compares two string" << endl
                 << "4. Checks whether string is palindrome or not" << endl
                 << "5. String Number Addition" << endl
                 << "6. exit" << endl;
            clear(buf);
            recv(c_sock, &buf, sizeof(buf), 0);
            string str1, str2;
            char c;
            bool flag;
            int val;
            switch (buf[0])
            {
            case '1':
                recv(c_sock, &str1, sizeof(str1), 0);
                recv(c_sock, &str2, sizeof(str1), 0);
                str1.append(str2);
                cout << "Concatenated string is: " << str1 << endl;
                break;
            case '2':

                recv(c_sock, &c, sizeof(c), 0);
                recv(c_sock, &str1, sizeof(str1), 0);
                flag = false;
                for (int i = 0; i < str1.length(); i++)
                {
                    if (str1[i] == c)
                    {
                        val = i;
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                    cout << "First occurence of " << c << " is at -1 index" << endl;
                else
                    cout << "First occurence of " << c << " is at " << val << " index" << endl;
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                break;
            case '6':
                break;
            default:
                break;
            }
            close(c_sock);

            exit(0); // you can safely terminate the child process-&gt; parent is still listening for new clients
        }
    }

    close(s_sock);

    return 0;
}