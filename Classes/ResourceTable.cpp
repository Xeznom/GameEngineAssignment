#include "ResourceTable.h"

#include <iostream>
#include <fstream>

CResourceTable* CResourceTable::instance; 

CResourceTable::CResourceTable(void)
{
	label = cocos2d::Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);

	std::ifstream myfile;
	myfile.open("ResourceTable.txt");
	if (myfile.is_open())
	{
		std::string line;
		while ( std::getline (myfile,line) )
		{
			std::size_t pos = line.find(':');
			std::string Name = line.substr(0,pos);

			std::string* Data = new std::string;
			*Data = line.substr(pos+1);

			rtable[Name] = Data;
		}
		myfile.close();
	}

	myfile.open("DataTable.txt");
	if (myfile.is_open())
	{
		std::string line;
		while ( std::getline (myfile,line) )
		{
			std::size_t pos = line.find(':');
			std::string Name = line.substr(0,pos);
			
			dtable[Name] =  std::stoi(line.substr(pos+1));
		}
		myfile.close();
	}
}

CResourceTable::~CResourceTable(void)
{
	 for (std::map<std::string,std::string*>::iterator it=rtable.begin(); it!=rtable.end(); ++it)
		 delete it->second;

	 rtable.clear();
	 dtable.clear();

	delete instance;
	instance = nullptr;
}
