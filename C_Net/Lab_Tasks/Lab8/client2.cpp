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
	char request[256];
	char buf[200];

	// create the socket
	int sock;
	sock = socket(AF_INET, SOCK_STREAM, 0);

	// setup an address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;

	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(3001);

	connect(sock, (struct sockaddr *)&server_address, sizeof(server_address));
	char c;

	clear(request);
	cout << "Choose: ";
	cin >> c;
	cin.ignore();
	send(sock, &c, sizeof(c), 0);

	string str1, str2;
	char find;
	switch (c)
	{
	case '1':

		cout << "Enter first str" << endl;
		getline(cin, str1);

		send(sock, &str1, sizeof(str1), 0);
		cout << "Enter second str" << endl;
		getline(cin, str2);
		send(sock, &str2, sizeof(str2), 0);
		break;
	case '2':
		cout << "enter char" << endl;
		cin >> find;
		cin.ignore();
		send(sock, &find, sizeof(find), 0);
		cout << "enter string" << endl;
		getline(cin, str1);
		send(sock, &str1, sizeof(str1), 0);

		break;
	default:
		break;
	}
	close(sock);
	return 0;
}