#pragma once

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <Ws2tcpip.h>
#include <thread>
#include <atomic>

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT 9999

class Client
{
public:
	Client();
	~Client();

	bool Init(int argc, _TCHAR *argv[]);
	void Update();
	void CleanUp();
private:
	void RecieveMessages(SOCKET connectSocket);

private:
	WSADATA m_wsaData;
	SOCKET m_connectSocket = INVALID_SOCKET;
	struct sockaddr_in m_servaddr;
	int m_iResult;

	std::thread m_recieveThread;
};

