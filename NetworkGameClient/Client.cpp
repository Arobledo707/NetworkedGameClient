#include "Client.h"



Client::Client()
{
	m_commandInfo.emplace(Command::Challenge, "\nChallenge a player to a game");
	m_commandInfo.emplace(Command::Login, "{username} {passsword}\nLogs in user");
	m_commandInfo.emplace(Command::Logout, "\nLogs out");
	m_commandInfo.emplace(Command::Chat, "{message}\nSends chat message to server");
	m_commandInfo.emplace(Command::Commands, "\nDisplays list of available commands");
	m_commandInfo.emplace(Command::Info, "{playername}\nGets Info about a player");
	m_commandInfo.emplace(Command::Quit, "\nQuits the client and disconnects from server.");
	m_commandInfo.emplace(Command::List, "\nLists all players currently online");
	m_commandInfo.emplace(Command::Help, "{command}\nShows info about a specified command");
}


Client::~Client()
{
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

	m_recieveThread = std::thread(&Client::RecieveMessages, this);
	//CreateThread(NULL, 0, RecieveMessage, (LPVOID)m_connectSocket, 0, 0);

	return true;
}

void Client::Update()
{
	std::string inputString;
	for (;;)
	{
		std::getline(std::cin, inputString);

		ProcessInput(inputString);
	}
}

void Client::CleanUp()
{
	m_recieveThread.join();
	WSACleanup();
}


void Client::RecieveMessages()
{
	char recvbuf[DEFAULT_BUFLEN];
	memset(recvbuf, 0, sizeof(char) * DEFAULT_BUFLEN);
	SOCKET connfd = (SOCKET)m_connectSocket;
	int iResult;

	while (true)
	{
		memset(recvbuf, 0, sizeof(char) * DEFAULT_BUFLEN);
		iResult = recv(connfd, recvbuf, sizeof(recvbuf), 0);

		if (iResult == SOCKET_ERROR) 
		{
			std::cout << "recv failed: " << WSAGetLastError() << std::endl;
		}
		else 
		{
			std::cout << recvbuf << std::endl;
		}
	}
}

void Client::ProcessInput(std::string input)
{
	ServerCommand servCommand;

	if (input.substr(0, m_commands[Command::Login].size()) == m_commands[Command::Login]) 
	{
		servCommand.set_command(Command::Login);
		//servCommand.set_content(input.substr(m_commands[Command::Login].size() + 1, input.size()));

		if (input.size() == m_commands[Command::Login].size()) 
		{
			std::cout << "Error: no username or password entered.\nLogin {username} {password}" << std::endl;
			return;
		}

		std::string userName;

		int j = static_cast<int>(m_commands[Command::Login].size() + 1);

		while (input[j] != ' ' && j <= input.size()-1)
		{
			userName += input[j];
			++j;
		}

		if (input.length() < m_commands[Command::Login].size() + userName.length())
		{
			std::cout << "Error: no password entered" << std::endl;
			return;
		}

		//Add username and password
		servCommand.add_content(userName.c_str(), userName.size());
		std::string password = input.substr((j+1), input.length());
		servCommand.add_content(password.c_str(), password.size());
	}
	else if (input.substr(0, m_commands[Command::Info].size()) == m_commands[Command::Info])
	{
		servCommand.set_command(Command::Info);
		servCommand.add_content(input.substr(m_commands[Command::Info].size() + 1, input.size()));
	}

	else if (input.substr(0, m_commands[Command::Quit].size()) == m_commands[Command::Quit])
	{
		servCommand.set_command(Command::Quit);
		servCommand.add_content(input.substr(m_commands[Command::Quit].size() + 1, input.size()));

	}

	else if (input.substr(0, m_commands[Command::Challenge].size()) == m_commands[Command::Challenge])
	{
		servCommand.set_command(Command::Challenge);
		servCommand.add_content(input.substr(m_commands[Command::Challenge].size() + 1, input.size()));


	}

	else if (input.substr(0, m_commands[Command::Chat].size()) == m_commands[Command::Chat])
	{
		servCommand.set_command(Command::Chat);
		servCommand.add_content(input.substr(m_commands[Command::Chat].size() + 1, input.size()));
	}

	else if (input.substr(0, m_commands[Command::Logout].size()) == m_commands[Command::Logout])
	{
		servCommand.set_command(Command::Logout);
		servCommand.add_content(input.substr(m_commands[Command::Logout].size() + 1, input.size()));
	}

	else if (input.substr(0, m_commands[Command::List].size()) == m_commands[Command::List])
	{
		servCommand.set_command(Command::List);
		servCommand.add_content(input.substr(m_commands[Command::List].size() + 1, input.size()));
	}

	else if (input.substr(0, m_commands[Command::Commands].size()) == m_commands[Command::Commands])
	{
		servCommand.set_command(Command::Commands);

		for (auto pair : m_commandInfo)
		{
			std::cout << m_commands[pair.first] << ": " << pair.second << std::endl;
		}
		return;
	}
	else if (input.substr(0, m_commands[Command::Commands].size()) == m_commands[Command::Commands])
	{
		servCommand.set_command(Command::Help);
		servCommand.add_content(input.substr(m_commands[Command::Help].size() + 1, input.size()));
		return;
	}



	if (servCommand.has_command()) 
	{
		std::string commands = servCommand.SerializeAsString();
		std::string lolok = servCommand.content(0);
		m_iResult = send(m_connectSocket, commands.c_str(), static_cast<int>(commands.length()), 0);

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
		std::cout << m_commands[info.first] << " " << info.second << std::endl;
	}
}
