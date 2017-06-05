#include "stdafx.h"
#include "Copy.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
using parse::Parse_Strings;

namespace fileMan {

	Copy::Copy()
	{
		setOp("*>");
	}

	void Copy::copyTo(string source, string destination) {

		ifstream sourceFileStream(source);
		ofstream destinationFileStream(destination);
		if (sourceFileStream.is_open() && destinationFileStream.is_open()) {
			string lineIn;
			while (getline(sourceFileStream, lineIn)) {
				destinationFileStream << lineIn << endl;
			}
			sourceFileStream.close();
			destinationFileStream.close();
			cout << "Copy successful!" << endl;
		}
		else {
			cout << "Something wrong with source and destination files." << endl;
			sourceFileStream.close();
			destinationFileStream.close();
		}
	}


	// Test if copy operator is used
	void Copy::checkOp(string toTest) {
		Parse_Strings p;
		if (toTest.find(getOp()) != string::npos) {
			vector<string> use(2);
			use = p.split_string(toTest, getOp());
			copyTo(use[0], use[1]);
			p.test(p.getCheck());
		}
	}

	Copy::~Copy()
	{
	}
}