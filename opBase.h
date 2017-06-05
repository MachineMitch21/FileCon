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
	~opBase();
private:
	 std::string Op;
};

#endif