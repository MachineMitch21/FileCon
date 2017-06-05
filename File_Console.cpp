// File_Console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Copy.h"
#include "Move.h"
#include "opBase.h"
#include "Parse_Strings.h"
#include <iostream>
#include <fstream>
#include "Delete.h"
#include <Windows.h>

using std::string;
using std::cout;
using std::getline;
using std::cin;
using std::endl;
using fileMan::Copy;
using fileMan::Delete;
using fileMan::Move;
using parse::Parse_Strings;

void test_opChange(string toTest, Copy &c, Move &v, Delete &d);

int _tmain(int argc, _TCHAR* argv[])
{
	bool active = true;
	string entry;
	Copy c;
	Move m;
	Delete d;
	Parse_Strings p;

	// Main loop
	while (active){
		
		// Getting the command
		cout << "command < ";
		getline(cin, entry);

		p.initial_parse(entry, true);
		test_opChange(entry, c, m, d);
	}

	return 0;
}


void test_opChange(string toTest, Copy &c, Move &v, Delete &d) {

	if (toTest == "change_op") {
		
		int answer;
		string newOp;
		cout << "Which operator would you like to change?:" << endl;
		cout << "1. " << "(*" << c.getOpName() << "*)::		" << c.getOp() << endl;
		cout << "2. " << "(*" << v.getOpName() << "*)::		" << v.getOp() << endl;
		cout << "3. " << "(*" << d.getOpName() << "*)::		" << d.getOp() << endl;
		cin >> answer;
		switch (answer)
		{
		case 1:
			cout << "What would you like to change it to?:" << endl;
			cin >> newOp;
			c.setOp(newOp);
			cout << "Operator changed" << endl;
			break;
		case 2:
			cout << "What would you like to change it to?:" << endl;
			cin >> newOp;
			v.setOp(newOp);
			cout << "Operator changed" << endl;
			break;
		case 3:
			cout << "What would you like to change it to?: " << endl;
			cin >> newOp;
			d.setOp(newOp);
			cout << "Operator changed" << endl;
			break;
		default:
			cout << "Not a valid option." << endl;
			break;
		}
	}
}