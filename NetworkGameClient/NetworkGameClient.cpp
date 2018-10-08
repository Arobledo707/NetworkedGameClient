// NetworkGameClient.cpp : Defines the entry point for the console application.
//

#include "Client.h"


int _tmain(int argc, _TCHAR *argv[])
{
	Client client;
	if (!client.Init(argc, argv)) 
	{
		return 0;
	}

	client.Update();
	client.CleanUp();
    return 0;
}

