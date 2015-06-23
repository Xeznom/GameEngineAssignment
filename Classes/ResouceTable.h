#ifndef __CRESROUCETABLE_H__
#define __CRESROUCETABLE_H__

#pragma once

#include "cocos2d.h"
#include <map>
#include <string>

class CResouceTable
{
private:
	static CResouceTable* instance;
	CResouceTable(void);
	static const char* filename;
	std::map<std::string,std::string*> table;
public:
	cocos2d::Label* label;
	inline static CResouceTable* getInstance()
	{
		if (instance == nullptr) instance = new CResouceTable();
		return instance;
	}
	~CResouceTable(void);
	inline const std::string GetFileName (const std::string name){return *table[name];}
};

#endif