#ifndef MY_MAP_H
#define MY_MAP_H
#include <iostream>
#include <string>
#include <map>

class My_Map
{
public:
	My_Map();
	~My_Map();

	std::map<char, char> UpperMap();
	std::map<char, char> LowerMap();
	void insertN(std::map<char, char> &M, char L, char S);
	void changeV(std::map<char, char> &M);
	void checkL();
};

#endif