#include "Client.h"



Client::Client()
{
	m_commandInfo.emplace(Command::Challenge, "Challenge a player to a game");
	m_commandInfo.emplace(Command::Login, "Login name password");
	m_commandInfo.emplace(Command::Logout, "Logs out");
	m_commandInfo.emplace(Command::Chat, "Sends chat message to server");
	m_commandInfo.emplace(Command::Commands, "Displays list of available commands");
	m_commandInfo.emplace(Command::Info, "Gets Info about a player");



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
	//TODO go back to std::thread soon
	// swapped back to create thread just for a bit

	//passing this into thread is not good
	// TODO fix later
	//m_recieveThread = std::thread(&Client::RecieveMessages, m_connectSocket);
	CreateThread(NULL, 0, RecieveMessage, (LPVOID)m_connectSocket, 0, 0);

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
		m_iResult = send(m_connectSocket, inputString.c_str(), inputString.length(), 0);

		if (m_iResult == SOCKET_ERROR)
		{
			std::cout << "send failed: " << WSAGetLastError() << std::endl;
		}
		
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
	int iResult;

	for (;;)
	{
		memset(recvbuf, 0, sizeof(char) * DEFAULT_BUFLEN);
		iResult = recv(connfd, recvbuf, sizeof(recvbuf), 0);

		if (iResult == SOCKET_ERROR) 
		{
			std::cout << "recv failed: " << WSAGetLastError() << std::endl;
		}
		else 
		{
			printf(recvbuf);
			printf("\n");
		}
	}
}

void Client::ProcessInput(std::string input)
{
	ServerCommand servCommand;

	if (input.substr(0, m_commands[Command::Login].size()) == m_commands[Command::Login]) 
	{
		servCommand.set_command(Command::Login);
	}
	else if (input.substr(0, m_commands[Command::Info].size()) == m_commands[Command::Info])
	{
		servCommand.set_command(Command::Info);
	}

	else if (input.substr(0, m_commands[Command::Quit].size()) == m_commands[Command::Quit])
	{
		servCommand.set_command(Command::Quit);
	}

	else if (input.substr(0, m_commands[Command::Challenge].size()) == m_commands[Command::Challenge])
	{
		servCommand.set_command(Command::Challenge);
	}

	else if (input.substr(0, m_commands[Command::Chat].size()) == m_commands[Command::Chat])
	{
		servCommand.set_command(Command::Chat);
	}

	else if (input.substr(0, m_commands[Command::Logout].size()) == m_commands[Command::Logout])
	{
		servCommand.set_command(Command::Logout);

	}

	else if (input.substr(0, m_commands[Command::List].size()) == m_commands[Command::List])
	{
		servCommand.set_command(Command::List);

	}

	else if (input.substr(0, m_commands[Command::Commands].size()) == m_commands[Command::Commands])
	{
		servCommand.set_command(Command::Commands);

		return;

	}
	else if (input.substr(0, m_commands[Command::Commands].size()) == m_commands[Command::Commands])
	{
		servCommand.set_command(Command::Help);

		return;
	}



	if (servCommand.has_command()) 
	{
		std::string commands = servCommand.SerializeAsString();
		m_iResult = send(m_connectSocket, commands.c_str(), commands.length(), 0);

		if (m_iResult == SOCKET_ERROR)
		{
			std::cout << "send failed: " << WSAGetLastError() << std::endl;
		}
	}

}

void Client::PrintCommands()
{
	std::cout << "Here are the available commands: " << std::endl;
	for (std::pair<Command, std::string> info : m_commandInfo) 
	{
		std::cout << m_commands[info.first] << ": " << info.second << std::endl;
	}
}
