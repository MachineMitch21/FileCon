#include "stdafx.h"
#include "Net_Parse.h"
#include <iostream>
#include "Net_Chat.h"

using std::string;
using net::Net_Chat;

namespace parse {

	Net_Parse::Net_Parse()
	{
	}
	bool Net_Parse::initial_net(string entry, bool active) {


		if (entry == "exit") {
			active = false;
			system("cls");
			return active;
		}
		else
		{
			net_check(entry);
			return true;
		}
	}

	void Net_Parse::net_check(string check) {
		test_net_chat(check);
	}

	void Net_Parse::test_net_chat(string check) {
		Net_Chat nc;

		if (check == "start chat") {
			nc.chat_menu();
		}
	}
	Net_Parse::~Net_Parse()
	{
	}
}