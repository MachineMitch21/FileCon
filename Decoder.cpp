#include "stdafx.h"
#include "Decoder.h"
#include "Encoder.h"
#include <map>
#include "My_Map.h"
#include <string>

using std::string;
using std::map;
using std::cout;
using std::endl;

Decoder::Decoder()
{
}

string Decoder::decodeMessage(string message){
	My_Map My;
	Encoder E;
	
	// This is filling a new map with the returned value of fillmap()

	map<char, char> Up = My.UpperMap();
	map<char, char> Low = My.LowerMap();
	int count = 1;
	//checks each subindex of message against every single one of our map values
	cout << message << endl;
	
		for (int x = 0; x < message.size(); ++x) {
			if (message[x] == '+') {
				for (map<char, char>::iterator i = Up.begin(); i != Up.end(); ++i) {

					if (message[x + 1] == i->second) {

						message[x + 1] = i->first;
					}
					else if (message[x] == ' ') {

						message[x] = message[x];
					}
				}
		

			if (message[x] == '~') {
				for (map<char, char>::iterator i = Low.begin(); i != Low.end(); ++i) {

					if (message[x + 1] == i->second) {

						message[x + 1] = i->first;
					}
					else if (message[x] == ' ') {

						message[x] = message[x];
					}
				}
			}
			if (message[x] == '"') {
				message[x + 1] = message[x + 1];
			}
		}
	}

	return message;
}

Decoder::~Decoder()
{
}
