#include "stdafx.h"
#include "My_Map.h"
#include "Encoder.h"
#include "Decoder.h"

using std::map;
using std::pair;
using std::cout;
using std::endl;
using std::cin;

My_Map::My_Map()
{
}

map<char, char> My_Map::UpperMap(){
	map<char, char> H;
	insertN(H, 'A', '`');
	insertN(H, 'B', '!');
	insertN(H, 'C', '@');
	insertN(H, 'D', '#');
	insertN(H, 'E', '$');
	insertN(H, 'F', '%');
	insertN(H, 'G', '^');
	insertN(H, 'H', '&');
	insertN(H, 'I', '*');
	insertN(H, 'J', '(');
	insertN(H, 'K', ')');
	insertN(H, 'L', '-');
	insertN(H, 'M', '_');
	insertN(H, 'N', '=');
	insertN(H, 'O', '|');
	insertN(H, 'P', '}');
	insertN(H, 'Q', ']');
	insertN(H, 'R', '[');
	insertN(H, 'S', '{');
	insertN(H, 'T', ';');
	insertN(H, 'U', ':');
	insertN(H, 'V', '<');
	insertN(H, 'W', '>');
	insertN(H, 'X', '.');
	insertN(H, 'Y', ',');
	insertN(H, 'Z', '?');
	return H;
}

map<char, char> My_Map::LowerMap() {
	map<char, char> H;
	insertN(H, 'a', '`');
	insertN(H, 'b', '!');
	insertN(H, 'c', '@');
	insertN(H, 'd', '#');
	insertN(H, 'e', '$');
	insertN(H, 'f', '%');
	insertN(H, 'g', '^');
	insertN(H, 'h', '&');
	insertN(H, 'i', '*');
	insertN(H, 'j', '(');
	insertN(H, 'k', ')');
	insertN(H, 'l', '-');
	insertN(H, 'm', '_');
	insertN(H, 'n', '=');
	insertN(H, 'o', '|');
	insertN(H, 'p', '}');
	insertN(H, 'q', ']');
	insertN(H, 'r', '[');
	insertN(H, 's', '{');
	insertN(H, 't', ';');
	insertN(H, 'u', ':');
	insertN(H, 'v', '<');
	insertN(H, 'w', '>');
	insertN(H, 'x', '.');
	insertN(H, 'y', ',');
	insertN(H, 'z', '?');
	return H;
}

void My_Map::insertN(map<char, char> &M, char L, char S){
	M.insert(pair<char, char>(L, S));
}

void My_Map::checkL(){
	Encoder encode;
	map <char, char> M = LowerMap();
	char A;
	cout << "Would you like to change any of the symbols for the encoder? y or n" << endl;
	cin >> A;
	switch (A){
	case 'y':
		changeV(M);
		break;
	case 'n':
		break;
	default:
		cout << "Invalid entry" << endl;
	}
}


void My_Map::changeV(map<char, char> &M){
	Encoder encode;
	char C;
	pair<char, char> P;
	cout << "Enter the capital letter that correlates with the symbol you want it encrypted with." << endl;
	cin >> C;
	for (map<char, char>::iterator i = M.begin(); i != M.end(); ++i){
		P = *i;
		if (P.first == C){
			cout << "Enter the symbol you want to be in place of the current symbol." << endl;
			cin >> C;
			i->second = C;
			cout << "This is the letter: " << P.first << "This is the symbol: " << i->second << endl;
		}
	}
}

My_Map::~My_Map()
{
}
