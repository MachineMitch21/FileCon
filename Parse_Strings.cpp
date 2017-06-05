#include "stdafx.h"
#include "Parse_Strings.h"
#include <string>
#include <iostream>
#include "Copy.h"
#include <vector>
#include "Move.h"
#include "Delete.h"
#include "Net_Mode.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using fileMan::Copy;
using fileMan::Move;
using fileMan::Delete;
using net::Net_Mode;

namespace parse {

	Parse_Strings::Parse_Strings()
	{
	}

	// Checks to see if command is exit, if not passes to be checked by others
	bool Parse_Strings::initial_parse(string entry, bool active) {
		Parse_Strings::toCheck = entry;
		if (entry == "exit") {
			active = false;
			return active;
		}
		else {
			// To check for other commands
			test(toCheck);
			return active;
		}
	}

	// Checking all commands
	void Parse_Strings::test(string entry) {
		Copy c;
		Move m;
		c.checkOp(entry);
		m.checkOp(entry);
		test_delete(entry);
		test_net(entry);
	}



	void Parse_Strings::test_delete(string toTest) {
		Delete d;
		string op = d.getOp();
		if (toTest.find(op) != string::npos) {
			vector<string> use(2);
			use = split_string(toTest, op);
			d.deleteP(use[1]);
		}
	}

	vector<string> Parse_Strings::split_string(string toSplit, string delimiter) {
		vector<string> ready(2);

		toSplit = remove_space(toSplit);
		vector<int> paths = collect_pieces(toSplit);
		string toSplit2 = toSplit.substr(0, paths[3] + 1);
		string pass = toSplit.substr(toSplit.find(delimiter) + delimiter.size(), toSplit.size());
		ready[0] = toSplit2.substr(0, toSplit2.find(delimiter));
		ready[1] = toSplit2.substr(toSplit2.find(delimiter) + delimiter.size(), toSplit2.size());
		toCheck = pass;
		return ready;
	}

	string Parse_Strings::remove_space(string toCheck) {

		vector<int> subs = collect_pieces(toCheck);										// Gets the start and end for each file path in the string
																						// from collect pieces.

		/*
			The marker is set to 1 to remove the spaces between the
			end of the first file path and the operator.
		*/
		int marker = 1;

		for (int i = 0; i < toCheck.size(); i++) {
			/*
				If the subindex of the string is a space and it is before the start
				or after the end of the the file path, run inner loop.
			*/
			if (toCheck[i] == ' ' && i > subs[marker] && i <= subs[marker + 1]) {
				/*
					Overrite the subindex with the space and shift
					everything to the left to remove the space.
				*/
				for (int j = i; j < toCheck.size(); j++) {
					toCheck[j] = toCheck[j + 1];
				}
				/*
					Since everything was shifted collect pieces
					needs to be run again to get the new start and end locations
					for each file path in the string.
				*/
				subs = collect_pieces(toCheck);
			}
			/*
				If the current subindex is equal to the start of the
				next file path, skip over the path.
			*/
			if (i == subs[marker + 1]) {
				marker += 2;
			}
		}
		return toCheck;
	}


	vector<int> Parse_Strings::collect_pieces(string toCheck) {

		vector<int> locations;

		for (int i = 0; i <= toCheck.size(); i++)
		{
			if (toCheck[i] == ':') {									// Finds starting point of file path
				locations.push_back(i - 1);
			}
			if (toCheck[i] == '.') {									// Finds end of file path
				locations.push_back(i + 3);
			}
		}

		locations.push_back((int)toCheck.size() + 1);
		return locations;
	}

	void Parse_Strings::test_net(string toCheck) {
		Net_Mode n;
		if (toCheck == "net mode") {
			n.net();
		}
	}

	string Parse_Strings::getCheck() {
		return Parse_Strings::toCheck;
	}

	Parse_Strings::~Parse_Strings()
	{
	}
}