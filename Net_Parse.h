#ifndef NET_PARSE_H
#define NET_PARSE_H

#include <string>

namespace parse {

	class Net_Parse
	{
	public:
		Net_Parse();

		bool initial_net(std::string entry, bool active);
		void net_check(std::string check);
		void test_net_chat(std::string check);

		~Net_Parse();
	};
}
#endif