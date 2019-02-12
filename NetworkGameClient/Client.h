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

#include "ServerCommands.pb.h"
#include "protoTest.pb.h"

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT 9999

class Client
{

private:
	 enum Command
	{
		Challenge,
		Info,
		Quit,
		Login,
		Logout,
		Chat,
		List,
		Commands,
		Help,
		CommandSize
	};


public:
	Client();
	~Client();

	bool Init(int argc, _TCHAR *argv[]);
	void Update();
	void CleanUp();
private:
	void RecieveMessages(SOCKET connectSocket);
	void ProcessInput(std::string input);
	void PrintCommands();

private:
	WSADATA m_wsaData;
	SOCKET m_connectSocket = INVALID_SOCKET;
	struct sockaddr_in m_servaddr;
	int m_iResult;
	Player* m_pPlayer;

	std::thread m_recieveThread;
	std::map<Command, std::string> m_commandInfo;
	std::vector<std::string> m_commands{ "Challenge", "Info", "Quit", "Login", "Logout", "Chat", "List", "Commands, Help" };
};

