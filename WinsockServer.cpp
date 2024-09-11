#include "WinsockServer.h"

WinsockServer::WinsockServer(const wchar_t* ip, unsigned int port) : ip_address(ip), port(port) {
	initWinDependencies();
	startServer();

};

WinsockServer::~WinsockServer() {
	WSACleanup();
}

void WinsockServer::initWinDependencies() {
	int load_wsa_dll = WSAStartup(MAKEWORD(2, 2), &wsa_data);
	if (load_wsa_dll != 0) {
		printf("WSAStartup failed: %d\n", load_wsa_dll);
	}
	else {
		printf("The Winsock dll found!\n");
		printf("The status: %s\n", wsa_data.szSystemStatus);
	}
}

void WinsockServer::startServer() {
	createSocket();
	bindSocket();
	listenSocket();
	acceptSocket();
}

void WinsockServer::createSocket() {
	socket_server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (socket_server == SOCKET_ERROR)
		printf("Error at socket(): %d\n", WSAGetLastError());
	else
		printf("socket() is OK!\n");
}

void WinsockServer::bindSocket() {
	socket_configs.sin_family = AF_INET;
	socket_configs.sin_port = htons(port);
	InetPton(AF_INET, ip_address, &socket_configs.sin_addr);
	if (bind(socket_server, (const sockaddr*)&socket_configs, sizeof(socket_configs)) == SOCKET_ERROR)
		wprintf(L"Bind is not ok: %d\n", WSAGetLastError());
	else
		printf("Bind is ok!\nIp:%ls port: %d\n", ip_address, port);
}

void WinsockServer::listenSocket() {
	if (listen(socket_server, SOMAXCONN) == SOCKET_ERROR)
		wprintf(L"Listen function failed with error: %d", WSAGetLastError());
	else
		wprintf(L"Listening on socket binding.....\n");
}

void WinsockServer::acceptSocket() {
		
	int client_info_size = sizeof(client_information);
	char client_ip[INET_ADDRSTRLEN];
	SOCKET accept_socket = accept(socket_server, (sockaddr*)&client_information, &client_info_size);

	if (accept_socket == SOCKET_ERROR)
		printf("Accept failed: %d\n", WSAGetLastError());
	else
		inet_ntop(AF_INET, &client_information.sin_addr, client_ip, sizeof(client_ip));
		unsigned short client_port = ntohs(client_information.sin_port);
		printf("Accept the connection from IP: %s and PORT: %d", client_ip, client_port);
}

