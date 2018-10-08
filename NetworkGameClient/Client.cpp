#include "Client.h"



Client::Client()
{
}


Client::~Client()
{
}

DWORD WINAPI RecieveMessage(LPVOID connectSocket)
{
	char recvbuf[DEFAULT_BUFLEN];
	memset(recvbuf, 0, sizeof(char) * DEFAULT_BUFLEN);
	SOCKET connfd = (SOCKET)connectSocket;

	for (;;)
	{
		memset(recvbuf, 0, sizeof(char) * DEFAULT_BUFLEN);
		recv(connfd, recvbuf, sizeof(recvbuf), 0);

		printf(recvbuf);
		printf("\n");
	}
	return 0;
}




bool Client::Init(int argc, _TCHAR *argv[])
{
	if (argc != 2)
	{
		printf("usage: %ls server-name\n", argv[0]);
		return false;
	}

	// Initialize Winsock
	m_iResult = WSAStartup(MAKEWORD(2, 2), &m_wsaData);
	if (m_iResult != 0)
	{
		printf("WSAStartup failed with error: %d\n", m_iResult);
		return false;
	}

	m_connectSocket = socket(AF_UNSPEC, SOCK_STREAM, IPPROTO_TCP);
	if (m_connectSocket == INVALID_SOCKET)
	{
		printf("socket failed with error: %ld\n", WSAGetLastError());
		WSACleanup();
		return false;;
	}

	ZeroMemory(&m_servaddr, sizeof(m_servaddr));
	m_servaddr.sin_family = AF_INET;
	m_servaddr.sin_port = htons(DEFAULT_PORT);
	m_iResult = InetPton(AF_INET, argv[1], &m_servaddr.sin_addr);
	if (m_iResult <= 0)
	{
		if (m_iResult == 0)
			printf("pAddrBuf parameter points to a string that is not a valid IPv4 dotted-decimal string or a valid IPv6 address string.");
		else
			printf("InetPton failed with error: %ld\n", WSAGetLastError());
		WSACleanup();
		return false;;
	}


	// Connect to server.
	m_iResult = connect(m_connectSocket, (sockaddr *)&m_servaddr, sizeof(m_servaddr));
	if (m_iResult == SOCKET_ERROR) {
		printf("connect failed: %ld\n", WSAGetLastError());
		closesocket(m_connectSocket);
		m_connectSocket = INVALID_SOCKET;
		WSACleanup();
		_getch();
		return false;
	}
	//passing this into thread is not good
	// TODO fix later
	m_recieveThread = std::thread(&Client::RecieveMessages, m_connectSocket);
	//CreateThread(NULL, 0, RecieveMessage, (LPVOID)m_connectSocket, 0, 0);

	return true;
}

void Client::Update()
{
	std::string inputString;
	const std::string clientQuit = "Quit";
	for (;;)
	{
		std::getline(std::cin, inputString);
		if (inputString == clientQuit)
		{
			exit(0);
			break;
		}
		send(m_connectSocket, inputString.c_str(), inputString.length(), 0);
		
	}
}

void Client::CleanUp()
{
	m_recieveThread.join();
	WSACleanup();
}

void Client::RecieveMessages(SOCKET connectSocket)
{
	char recvbuf[DEFAULT_BUFLEN];
	memset(recvbuf, 0, sizeof(char) * DEFAULT_BUFLEN);
	SOCKET connfd = (SOCKET)m_connectSocket;

	for (;;)
	{
		memset(recvbuf, 0, sizeof(char) * DEFAULT_BUFLEN);
		recv(connfd, recvbuf, sizeof(recvbuf), 0);

		printf(recvbuf);
		printf("\n");
	}
}
