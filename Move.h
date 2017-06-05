#ifndef MOVE_H
#define MOVE_H

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "opBase.h"
#include "Parse_Strings.h"

namespace fileMan {

	class Move : public opBase
	{

	public:
		Move();
		~Move();
		void moveTo(std::string source, std::string destination);
		void checkOp(std::string toTest);
	};
}
#endif
