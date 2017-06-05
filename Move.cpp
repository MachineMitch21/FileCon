#include "stdafx.h"
#include "Move.h"

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;
using parse::Parse_Strings;

namespace fileMan {

	Move::Move()
	{
		setOp("->");
	}


	void Move::moveTo(string source, string destination) {

		ifstream sourceFileStream(source);
		ofstream destinationFileStream(destination);
		if (sourceFileStream.is_open() && destinationFileStream.is_open()) {
			string line;
			while (getline(sourceFileStream, line)) {
				destinationFileStream << line << endl;
			}
			sourceFileStream.close();
			destinationFileStream.close();
			remove(source.c_str());
			cout << "Move successful!" << endl;
		}
		else
		{
			cout << "Something wrong with source or destination files." << endl;
			sourceFileStream.close();
			destinationFileStream.close();
		}
	}

	void Move::checkOp(string toTest) {
		Parse_Strings p;
		if (toTest.find(getOp()) != string::npos) {
			vector<string> use(2);
			use = p.split_string(toTest, getOp());
			moveTo(use[0], use[1]);
			p.test(p.getCheck());
		}
	}

	Move::~Move()
	{
	}
}