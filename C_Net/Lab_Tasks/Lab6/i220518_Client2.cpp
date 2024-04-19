// Client side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iostream>
#include <cstring>
using namespace std;
#define PORT 8080
#define MAXLINE 1024

// Driver code
int main()
{
    int sockfd;
    string buffer;
    struct sockaddr_in servaddr;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    int n, len;
    len = sizeof(servaddr);
    int op1, op2;
    string opcode;
    cout << "Enter First Operand: ";
    cin >> op1;
    sendto(sockfd, &op1, sizeof(int), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    cout << "Enter  Operation: ";
    cin>>opcode;
    sendto(sockfd, (const char *)opcode.c_str(), strlen(opcode.c_str()), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    cout << "Enter Second Operand: ";
    cin >> op2;
    sendto(sockfd, &op2, sizeof(int), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));

    close(sockfd);
    return 0;
}