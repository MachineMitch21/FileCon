#ifndef PARSE_STRINGS_H
#define PARSE_STRINGS_H

#include <string>
#include <vector>

namespace parse {

	class Parse_Strings
	{
	public:
		Parse_Strings();

		bool initial_parse(std::string arg, bool active);
		void test(std::string entry);
		std::vector<std::string> split_string(std::string toSplit, std::string delimiter);
		std::string getCheck();
		~Parse_Strings();

	private:

		void test_delete(std::string toTest);
		std::string remove_space(std::string toCheck);

		/*
		collect pieces finds the start and end of each file path
		in the string that is passed in. It returns a vector of integers
		that contains the start and end index of each path.
		*/
		std::vector<int> collect_pieces(std::string toCheck);

		std::string toCheck;
		void test_net(std::string toTest);
	};
}
#endif
