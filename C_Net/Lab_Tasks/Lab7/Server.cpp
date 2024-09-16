#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
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
    listen(s_sock, 5);
    int c_sock[2];
    c_sock[0] = accept(s_sock, NULL, NULL);
    c_sock[1] = accept(s_sock, NULL, NULL);
    for (int i = 0; i < 2; i++)
    {
        while (1)
        {
            clear(buf);
            recv(c_sock[i], &buf, sizeof(buf), 0);
            if (strcmp(buf, "exit") == 0)
            {
                send(c_sock[i], buf, strlen(buf), 0);
                break;
            }
            cout << "Client"<<i<<": " << buf << endl;
            cout << "Server: ";
            cin.getline(buf, 256);

            send(c_sock[i], buf, strlen(buf), 0);
            if (strcmp(buf, "exit") == 0)
            {
                break;
            }
        }
    }
    // close the socket
    close(s_sock);

    return 0;
}