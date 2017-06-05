#include "stdafx.h"
#include "Delete.h"

using std::string;
using std::cout;
using std::endl;
using std::exception;

namespace fileMan {

	Delete::Delete()
	{
	}

	string Delete::Op = "~";

	void Delete::deleteP(string Path) {
		try {
			remove(Path.c_str());
			cout << "Delete successful!" << endl;
		}
		catch (exception e) {
			cout << "Delete operation aborted." << endl;
		}


	}

	string Delete::getOp() {
		return Op;
	}

	void Delete::setOp(string op) {
		Op = op;
	}

	Delete::~Delete()
	{
	}
}