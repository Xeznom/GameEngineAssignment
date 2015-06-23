#include "ResouceTable.h"

#include <iostream>
#include <fstream>
#include <string>

CResouceTable* CResouceTable::instance; 
const char* CResouceTable::filename = "ResourceTable.txt";

CResouceTable::CResouceTable(void)
{
	label = cocos2d::Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	std::ifstream myfile;
	myfile.open(filename);

	if (myfile.is_open())
	{
		std::string line;
		while ( std::getline (myfile,line) )
		{
			std::size_t pos = line.find(':');
			std::string Name = line.substr(0,pos);
			std::string Data = line.substr(pos+1);
			table[Name.c_str()] = Data.c_str();
			label->setString(table[Name.c_str()]);
		}
		myfile.close();
	}
}

CResouceTable::~CResouceTable(void)
{
	delete instance;
}
