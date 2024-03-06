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
    char buffer[MAXLINE];
    struct sockaddr_in servaddr;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    string input;
    cout<<"Enter message: ";
    getline(cin, input);

    // memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    int n, len;
    len = sizeof(servaddr);
    sendto(sockfd, (const char *)input.c_str(), strlen(input.c_str()), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));

    n = recvfrom(sockfd, (char *)buffer, MAXLINE, 0, (struct sockaddr *)&servaddr, (socklen_t *) &len);
    buffer[n] = '\0';
    cout<<"you entered(Server) : "<<buffer<<endl;

    close(sockfd);
    return 0;
}