#include "stdafx.h"
#include "Delete.h"

using std::string;
using std::cout;
using std::endl;
using std::exception;
using std::vector;
using parse::Parse_Strings;

namespace fileMan {

	Delete::Delete()
	{
		setOp("~");
		setOpName("Delete");
	}

	void Delete::deleteP(string Path) {
		try {
			remove(Path.c_str());
			cout << "Delete successful!" << endl;
		}
		catch (exception e) {
			cout << "Delete operation aborted." << endl;
		}

	}

	void Delete::checkOp(string toTest) {
		Parse_Strings p;
		if (toTest.find(getOp()) != string::npos) {
			vector<string> use(2);
			use = p.split_string(toTest, getOp());
			deleteP(use[0]);
			p.test(p.getCheck());
		}
	}

	Delete::~Delete()
	{
	}
}