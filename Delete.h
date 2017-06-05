#ifndef DELETE_H
#define DELETE_H

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>

namespace fileMan {

	class Delete
	{
	public:
		Delete();
		~Delete();

		void deleteP(std::string path);
		std::string getOp();
		void setOp(std::string op);

	private:
		static std::string Op;
	};
}
#endif