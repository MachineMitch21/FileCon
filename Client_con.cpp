#include "stdafx.h"

#define WIN32_LEAN_AND_MEAN
#include "Client_con.h"

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include "Encoder.h"
#include "Decoder.h"
#include <vector>

#pragma comment(lib, "Ws2_32.lib")

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::vector;

namespace net {

	Client_con::Client_con()
	{
	}

	void Client_con::initializewinS() {
		
		Encoder E;
		Decoder D;
		// Initialize winsock
		WSADATA wsa;
		int Result;

		Result = WSAStartup(MAKEWORD(2, 2), &wsa);
		if (Result != 0) {
			cout << "startup failed: proper DLL not found." << endl;
		}

		// Getting addrinfo
		struct addrinfo *result = NULL, hints;

		// Padding unused parts of the structure
		ZeroMemory(&hints, sizeof(hints));
		// Filling out structure
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;

		// Get server address and port
		const char *IP;
		string tempIP;
		cout << "What is the IP address of the server?: " << endl;
		cin >> tempIP;

		const char *Port;
		string tempPort;
		cout << "What port number?: " << endl;
		cin >> tempPort;

		// Convert strings 
		IP = tempIP.c_str();
		Port = tempPort.c_str();

		Result = getaddrinfo(IP, Port, &hints, &result);
		if (Result != 0) {
			cout << "Something went wront with getaddrinfo" + WSAGetLastError() << endl;
			WSACleanup();
		}

		// Create the socket
		SOCKET Client;
		Client = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
		if (Client == INVALID_SOCKET) {
			cout << "Client socket could not be created: " + WSAGetLastError() << endl;
			freeaddrinfo(result);
			WSACleanup();
		}

		// Connect to server
		Result = connect(Client, result->ai_addr, (int)result->ai_addrlen);
		if (Result == SOCKET_ERROR) {
			closesocket(Client);
			Client = INVALID_SOCKET;
		}

		freeaddrinfo(result);

		if (Client == INVALID_SOCKET) {
			cout << "Could not connect to server!" << endl;
			WSACleanup();
		}
		
		vector<Encoder::ForMap> newVect(E.encodeInput("Hi"));
		cout << newVect.size() << endl;
		const char *sendbuf = ((E.Destructer(newVect)).c_str());
		cout << "sendbuf: ";
		cout << &sendbuf << endl;
		char recvbuf[512];

		// Send initial message
		//system("CLS");
		Result = send(Client, sendbuf, (int)strlen(sendbuf), 0);
		if (Result == SOCKET_ERROR) {
			cout << "send failed: " + WSAGetLastError() << endl;
			closesocket(Client);
			WSACleanup();
		}
		bool connected = true;
		if (connected == true) {
			cout << "Connected!" << endl;
			cout << endl;
		}
		while (connected == true) {
			// Recieve message
			Result = recv(Client, recvbuf, (int)strlen(recvbuf), 0);
			if (Result > 0)
			{
				string info;
				// Taking characters from buffer and putting them into string
				for (int i = 0; i < recvbuf[i] != NULL; ++i) {
					info += recvbuf[i];
				}
				info = D.decodeMessage(info);
				cout << "Server said: " << info << endl;
				// Clearing buffer
				for (int i = 0; i < info.length(); ++i) {
					recvbuf[i] = ' ';
				}
				cout << "you: ";
				string input;
				// Checking if new line was left in the stream
				if (cin.peek() == '\n') {
					cin.get();
				}
				// Getting input
				getline(cin, input);
				vector<Encoder::ForMap> newVect(E.encodeInput(input));
				sendbuf = E.Destructer(newVect).c_str();
				// Making all letters lowercase to check for stop
				transform(input.begin(), input.end(), input.begin(), tolower);
				if (input == "stop") {
					connected = false;
				}
				// Sending message
				Result = send(Client, sendbuf, (int)strlen(sendbuf), 0);
				if (Result == SOCKET_ERROR) {
					cout << "send failed: " + WSAGetLastError() << endl;
					closesocket(Client);
					WSACleanup();
					connected = false;
				}
			}

			else if (Result == 0) {
				cout << "Connection closed" << endl;
				connected = false;
			}

			else {
				cout << "receive failed" << endl;
				connected = false;
			}

		}

		// shut down the send half of the connection
		Result = shutdown(Client, SD_SEND);
		if (Result == SOCKET_ERROR) {
			cout << "Shutdown failed: " + WSAGetLastError() << endl;
			WSACleanup();
		}
		// Clean up 
		closesocket(Client);
		WSACleanup();
	}
	Client_con::~Client_con()
	{
	}
}