// Server side implementation of UDP client-server model
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
    struct sockaddr_in servaddr, cliaddr;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // memset(&servaddr, 0, sizeof(servaddr));
    // memset(&cliaddr, 0, sizeof(cliaddr));

    // Filling server information
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    int len, n;
    int op1, op2;
    char opcode;
    len = sizeof(cliaddr); // len is value/resuslt

    n = recvfrom(sockfd, &op1, MAXLINE, 0, (struct sockaddr *)&cliaddr, (socklen_t *)&len);
    cout << "OP1: " << op1 << endl;

    n = recvfrom(sockfd, (char *)buffer.c_str(), MAXLINE, 0, (struct sockaddr *)&cliaddr, (socklen_t *)&len);
    opcode = buffer[0];
    cout << "OPCODE: " << opcode << endl;

    n = recvfrom(sockfd, &op2, MAXLINE, 0, (struct sockaddr *)&cliaddr, (socklen_t *)&len);
    cout << "OP2: " << op2 << endl;
    int ans;
    switch (opcode)
    {
    case '+':
        ans = (op1 + op2);
        break;
    case '-':
        ans = (op1 - op2);
        break;
    case '/':
        ans = (op1 / op2);
        break;
    case '*':
        ans = (op1 * op2);
        break;
    }
    cout << "Result of " << op1 << " " << opcode << " " << op2 << " = " << ans << endl;

    return 0;
}