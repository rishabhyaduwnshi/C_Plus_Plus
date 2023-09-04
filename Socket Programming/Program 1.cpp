#include <iostream>
#include <winsock.h>
using namespace std;

struct sockaddr_in srv;
#define PORT 9999

int main()
{

	int nRet = 0;

	//Initialise the WSA Varibales for socket programming on Windows
	WSADATA ws;
	if(WSAStartup(MAKEWORD(2,2),&ws) < 0)
		std::cout << "WSA Initialisation Failed\n";
	else
		std::cout << "WSA Initialisation Successful\n";



	//Initialise the socket
	int nSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (nSocket < 0)
		std::cout << "Socket could not be opened\n";
	else
		std::cout << "Socket Opened\n";


	//Initialise the environment for sockaddr structure
	srv.sin_family = AF_INET;
	srv.sin_port = htons(PORT);
	srv.sin_addr.s_addr = INADDR_ANY; //collects the ip address of this machine
	memset(srv.sin_zero, 0, 8);



	//Bind the socket to local port
	nRet = bind(nSocket, (sockaddr*)&srv, sizeof(sockaddr));
	if (nRet < 0)
	{
		std::cout << "Binding failed\n";
		exit(EXIT_FAILURE);
	}
	else
		std::cout << "Binding Success\n";



	//Listen the request from client
	nRet = listen(nSocket, 5);
	if (nRet < 0)
	{
		std::cout << "Listening Failed\n";
		exit(EXIT_FAILURE);;
	}
	else
		std::cout << "Listening Started\n";


	//Keep waiting for new request and proceed as per the request
}
