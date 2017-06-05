#ifndef DELETE_H
#define DELETE_H

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Parse_Strings.h"
#include "opBase.h"

namespace fileMan {

	class Delete : public opBase
	{
	public:
		Delete();
		~Delete();

		void deleteP(std::string path);
		void checkOp(std::string toTest);
	};
}
#endif