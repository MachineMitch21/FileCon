#include "stdafx.h"
#include "opBase.h"

using std::string;

opBase::opBase()
{
}

void opBase::setOp(string op) {
	Op = op;
}

string opBase::getOp() {
	return Op;
}

void opBase::setOpName(string opName) {
	OpName = opName;
}

string opBase::getOpName() {
	return OpName;
}

opBase::~opBase()
{
}
