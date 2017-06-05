#ifndef COPY_H
#define COPY_H

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Parse_Strings.h"
#include "opBase.h"
#include <vector>

namespace fileMan {

	class Copy : public opBase
	{
	public:
		Copy();
		~Copy();

		void copyTo(std::string source, std::string destination);
		void checkOp(std::string toTest);
	private:

	};

}
#endif
