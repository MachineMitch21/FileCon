#include "stdafx.h"
#include "Net_Chat.h"
#include <iostream>
#include <string>
#include "Server_con.h"
#include "client_con.h"
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>

using std::cout;
using std::endl;
using std::cin;

namespace net {

	Net_Chat::Net_Chat()
	{
	}

	void Net_Chat::start_server() {

		Server_con S;
		S.initializeWinS();
	}

	void Net_Chat::start_client() {

		Client_con C;
		C.initializewinS();
	}

	void Net_Chat::chat_menu() {
		cout << "Which would you like?" << endl << endl;
		cout << "1. Be the server." << endl;
		cout << "2. Be the Client." << endl;

		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			start_server();
			break;
		case 2:
			start_client();
			break;
		default:
			cout << "Command not recognized." << endl;
			chat_menu();
			break;
		}
	}

	Net_Chat::~Net_Chat()
	{
	}
}