#include "ResourceTable.h"

#include <fstream>

CResourceTable* CResourceTable::instance;

CResourceTable::CResourceTable(void)
{
	if (instance == nullptr)
	{
		// Get absolute path of file
		std::string fullPath = cocos2d::CCFileUtils::getInstance()->fullPathForFilename("ResourceTable.txt");

		// Get data of file
		ssize_t fileSize;
		unsigned char* fileContents = cocos2d::CCFileUtils::getInstance()->getFileData(fullPath.c_str(), "r", &fileSize);

		std::string contents ( (char *)fileContents );

		// Create a string stream so that we can use getline( ) on it
		std::istringstream fileStringStream(contents);

		std::string Line;
		// Get file contents line by line
		while (getline(fileStringStream, Line))
		{
			std::size_t pos = Line.find(':');
			if (pos == std::string::npos) break;
			std::string Name = Line.substr(0, pos);

			std::string* Data = new std::string;
			*Data = Line.substr(pos + 1);
			Data->pop_back();

			std::string Extension = Data->substr(Data->rfind('.'));
			std::transform(Extension.begin(), Extension.end(), Extension.begin(), tolower);

			if (Extension.compare(".mp3") == 0)
				music_table[Name] = Data;
			else if (Extension.compare(".png") == 0)
				texture_table[Name] = Data;
			else if (Extension.compare(".csv") == 0)
				map_table[Name] = Data;
			rtable[Name] = Data;
		}

		// Delete buffer created by fileContents. This part is required.
		if (fileContents)
		{
			delete[] fileContents;
			fileContents = nullptr;
		}

		// Get absolute path of file
		fullPath = cocos2d::CCFileUtils::getInstance()->fullPathForFilename("DataTable.txt");

		// Get data of file
		fileContents = cocos2d::CCFileUtils::getInstance()->getFileData(fullPath.c_str(), "r", &fileSize);

		contents = std::string((char *)fileContents);

		// Create a string stream so that we can use getline( ) on it
		fileStringStream = std::istringstream(contents);

		// Get file contents line by line
		while (getline(fileStringStream, Line))
		{
			std::size_t pos = Line.find(':');
			if (pos == std::string::npos) break;
			std::string Name = Line.substr(0, pos);

			int data = std::stoi(Line.substr(pos + 1));
			data_table[Name] = data;
		}

		// Delete buffer created by fileContents. This part is required.
		if (fileContents)
		{
			delete[] fileContents;
			fileContents = nullptr;
		}
	}
}

CResourceTable::~CResourceTable(void)
{
	 for (std::map<std::string,std::string*>::iterator it=rtable.begin(); it!=rtable.end(); ++it)
		 delete it->second;

	delete instance;
	instance = nullptr;
}
