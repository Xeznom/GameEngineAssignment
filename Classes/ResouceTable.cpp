#include "ResouceTable.h"

#include <iostream>
#include <fstream>

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
			std::string* Data = new std::string;
			*Data = line.substr(pos+1);
			table[Name] = Data;
		}
		myfile.close();
	}
}

CResouceTable::~CResouceTable(void)
{
	 for (std::map<std::string,std::string*>::iterator it=table.begin(); it!=table.end(); ++it)
		 delete it->second;
	delete instance;
}
