#include "stdafx.h"
#include "Net_Mode.h"
#include <iostream>
#include "Net_Parse.h"
#include <string>

using std::cout;
using std::cin;
using std::string;
using parse::Net_Parse;


namespace net {

	Net_Mode::Net_Mode()
	{
	}


	void Net_Mode::net() {
		bool active = true;
		string entry;
		Net_Parse p;

		system("cls");

		while (active) {

			cout << "net mode < ";
			cin.sync();
			getline(cin, entry);
			active = p.initial_net(entry, active);
		}
	}


	Net_Mode::~Net_Mode()
	{
	}
}