#ifndef OPBASE_H
#define OPBASE_H

#include <string>
#include <iostream>

class opBase
{
public:
	opBase();
	virtual void checkOp(std::string toCheck) = 0;
	void setOp(std::string op);
	std::string getOp();
	void setOpName(std::string opName);
	std::string getOpName();
	~opBase();

private:
	 std::string Op;
	 std::string OpName = "Undefined Name";
};

#endif