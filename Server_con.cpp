#define WIN32_LEAN_AND_MEAN 
#include "stdafx.h"
#include "Server_con.h"
#include <string>

#pragma comment(lib, "Ws2_32.lib")

// STD console headers
#include <sdkddkver.h>
#include <conio.h>
#include <stdio.h>
#include <algorithm>

// Socket header files
#include <WinSock2.h>
#include <Windows.h>
#include <WS2tcpip.h>
#include <iphlpapi.h>
#include <iostream>
#include <vector>
//other
#include "Encoder.h"
#include "Decoder.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;

namespace net {

	Server_con::Server_con()
	{
	}

	void Server_con::initializeWinS() {
		Encoder E;
		Decoder D;
		WSADATA wsaData;

		int iResult;

		// Initialize Winsock
		iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (iResult != 0) {
			printf("WSAStartup failed: %d\n", iResult);

		}
		struct addrinfo *result = NULL, hints;

		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
		hints.ai_flags = AI_PASSIVE;

		cout << "What port would you like to listen on?: " << endl;
		string  Iport;
		const char *port;
		cin >> Iport;
		port = Iport.c_str();
		// Resolve the local address and port to be used by the server
		iResult = getaddrinfo(NULL, port, &hints, &result);
		if (iResult != 0) {
			printf("getaddrinfo failed: %d\n", iResult);
			WSACleanup();

		}

		system("CLS");
		SOCKET ListenSocket = INVALID_SOCKET;

		// Create a SOCKET for the server to listen for client connections
		ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

		if (ListenSocket == INVALID_SOCKET) {
			printf("Error at socket(): %ld\n", WSAGetLastError());
			freeaddrinfo(result);
			WSACleanup();

		}

		// Setup the TCP listening socket
		iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
		if (iResult == SOCKET_ERROR)
		{
			printf("bind faild with error: %d\n", WSAGetLastError());
			freeaddrinfo(result);
			closesocket(ListenSocket);
			WSACleanup();

		}
		freeaddrinfo(result);

		iResult = listen(ListenSocket, SOMAXCONN);
		if (iResult == SOCKET_ERROR) {
			printf("Listen failed with error: %ld\n", WSAGetLastError());
			closesocket(ListenSocket);
			WSACleanup();

		}

		SOCKET ClientSocket = INVALID_SOCKET;

		// Accept a client socket
		ClientSocket = accept(ListenSocket, NULL, NULL);
		if (ClientSocket == INVALID_SOCKET) {
			printf("accept failed: %d\n", WSAGetLastError());
			closesocket(ListenSocket);
			WSACleanup();

		}

		char recvbuf[512];
		int  iSendResult;
		const char *sendbuf;
		bool connected = true;
		// Receive until the peer shuts down the connection
		while (connected == true) {
			iResult = recv(ClientSocket, recvbuf, 512, 0);
			if (iResult > 0) {
				string output;

				for (int i = 0; i < recvbuf[i] != NULL; ++i) {
					output += recvbuf[i];
				}
				output = D.decodeMessage(output);
				cout << "Client said: " << output << endl;
				// Clearing buffer
				for (int i = 0; i < output.length(); ++i) {
					recvbuf[i] = ' ';
				}
				// Respond
				string input;
				cout << "You: ";
				// Checking if new line was left in the stream
				if (cin.peek() == '\n') {
					cin.get();
				}
				// Getting message
				getline(cin, input);
				cout << "before" << endl;
				vector<Encoder::ForMap> newVect(E.encodeInput(input));
				cout << "after" << endl;
				sendbuf = E.Destructer(newVect).c_str();
				// Making all letters lowercase to check for stop
				transform(input.begin(), input.end(), input.begin(), tolower);
				if (input == "stop") {
					connected = false;
				}
				// Sending message
				iSendResult = send(ClientSocket, sendbuf, (int)strlen(sendbuf), 0);
				if (iSendResult == SOCKET_ERROR) {
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(ClientSocket);
					WSACleanup();

				}

			}
			else if (iResult == 0) {
				printf("Connection closing... \n");
				connected = false;
			}

			else {
				printf("recv failed: %d\n", WSAGetLastError());
				closesocket(ClientSocket);
				WSACleanup();
				connected = false;
			}

		}

		// shutdown the send half of the connection since no more data will be sent
		iResult = shutdown(ClientSocket, SD_SEND);
		if (iResult == SOCKET_ERROR) {
			printf("shutdown failed: %d\n", WSAGetLastError());
			closesocket(ClientSocket);
			WSACleanup();

		}

		// cleanup
		closesocket(ClientSocket);
		WSACleanup();
	}


	Server_con::~Server_con()
	{
	}
}