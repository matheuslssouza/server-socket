#include <iostream>
#include <string>
#include "WinsockServer.h"
#pragma comment(lib, "Ws2_32.lib")


int main() {
	
	WinsockServer WinsockServer(L"127.0.0.1", 4000);
	return 0;

}