#ifndef WINSOCK_SERVER_H
#define WINSOCK_SERVER_H
#pragma comment(lib, "Ws2_32.lib")
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <string>

class WinsockServer{
public:

	WinsockServer(const wchar_t* ip, unsigned int port);
	~WinsockServer();
	void initWinDependencies();
	void startServer();
	

private:
	WSADATA wsa_data;
	SOCKET socket_server;
	SOCKET accept_socket;
	sockaddr_in socket_configs;
	sockaddr_in client_information;
	const wchar_t* ip_address;
	unsigned int port;
		

	void createSocket();
	void bindSocket();
	void listenSocket();
	void acceptSocket();

};



#endif // !1

