#ifndef ENCODER_H
#define ENCODER_H
#include <iostream>
#include <string>
#include <map>
#include <vector>

class Encoder
{
public:
	struct ForMap {
		char Two;
		char One;
	};
	Encoder();
	~Encoder();
	std::vector<ForMap> encodeInput(std::string input);
	void decode(std::map<char, char> &M, std::string message);
	std::vector<ForMap> structVect;
	std::string Destructer(std::vector<ForMap> temp);
};

#endif