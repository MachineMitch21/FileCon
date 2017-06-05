#include "stdafx.h"
#include "Encoder.h"
#include "Decoder.h"
#include "My_Map.h"
#include <string>


using std::string;
using std::cout;
using std::endl;
using std::map;
using std::cin;
using std::vector;

Encoder::Encoder()
{
}



    std::vector<Encoder::ForMap> Encoder::encodeInput(string user){
		
	My_Map My;
	ForMap FM;
	
	// Filling a new map with the returned value of fillmap()
	map<char, char> Up = My.UpperMap();
	map<char, char> Low = My.LowerMap();
	// Changes all of the chars in user string to uppercase
	//for (int i = 0; i < user.length(); i++){
		//user[i] = toupper(user[i]);
	//}

	//iterates through our map checking every subindex of user against our map keys
	for (int x = 0; x < user.size(); ++x){
		if ((int)user[x] >= 65 && (int)user[x] <= 90) {
			
			for (map<char, char>::iterator i = Up.begin(); i != Up.end(); ++i) {

				if (user[x] == i->first) {
					user[x] = i->second;
					FM.One = user[x];
					FM.Two = '+';
					structVect.push_back(FM);
				}
				
			}
		}
		
		if ((int)user[x] >= 97 && (int)user[x] <= 122) {
			for (map<char, char>::iterator i = Low.begin(); i != Low.end(); ++i) {

				if (user[x] == i->first) {
					user[x] = i->second;
					FM.One = user[x];
					FM.Two = '~';
					structVect.push_back(FM);
				}
				else if (user[x] == ' ') {
					user[x] = user[x];
				}
				//This checks to see if the current subindex of user is equal to any of the map values because of punctuation.
				else if (user[x] == i->second) {
					user[x] = i->first;
				}
			}
		}
		else if (!(int)user[x] >= 65 && (int)user[x] <= 90 && !(int)user[x] >= 97 && (int)user[x] <= 122) {
			for (map<char, char>::iterator i = Low.begin(); i != Low.end(); ++i) {
				if (user[x] == ' ')
					user[x] = user[x];

				if (user[x] == i->second) {
					user[x] = user[x];
					FM.One = user[x];
					FM.Two = '"';
				}
			}
			
		}
	}
	return structVect;
}
void Encoder::decode(map<char, char> &M, string message){
	Decoder decode;
	int A;
	cout << "Would you like to run the decoder now?" << endl;
	cout << "1. yes" << endl;
	cout << "2. no" << endl;
	cin >> A;
	switch (A){
	case 1:
	//	decode.decodeMessage(M, message);
		break;
	case 2:
		cout << "Have a nice day!" << endl;
		break;
	default:
		cout << "Invalid entry, make sure you are either entering a 1 or a 2, please." << endl;
	}
}

string Encoder::Destructer(vector<ForMap> temp) {
	string S;
	
	for (int i = 0; i < temp.size(); i++) {
		S += temp[i].Two;
		S += temp[i].One;
	}
	cout << "Destructer" << endl;
	cout << S << endl;
	return S;
}
Encoder::~Encoder()
{
}
