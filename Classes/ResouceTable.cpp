#include "ResouceTable.h"

#include <iostream>
#include <fstream>
#include <string>

CResouceTable::CResouceTable(const char* filename)
{
	std::ifstream myfile;
	myfile.open(filename);

	if (myfile.is_open())
	{
		std::string line;
		while ( std::getline (myfile,line) )
		{
			std::size_t pos = line.find(':');
			std::string Name = line.substr(0,pos-1);
			std::string Data = line.substr(pos+1);
			table[Name.c_str()] = Data.c_str();
		}
		myfile.close();
	}
}


CResouceTable::~CResouceTable(void)
{
	delete instance;
}
