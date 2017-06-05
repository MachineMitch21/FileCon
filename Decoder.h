#ifndef DECODER_H
#define DECODER_H
#include <iostream>
#include <string>


class Decoder
{
public:
	Decoder();
	~Decoder();
	std::string decodeMessage(std::string message);
};

#endif