#ifndef __CResourceTable_H__
#define __CResourceTable_H__

#pragma once

#include "cocos2d.h"
#include <map>
#include <string>

#define GETFILE(X) CResourceTable::getInstance()->GetFileName(X)
#define GETVALUE(X) CResourceTable::getInstance()->GetValue(X)

class CResourceTable
{
private:
	static CResourceTable* instance;
	CResourceTable(void);
	std::map<std::string,std::string*> rtable;
	std::map<std::string,int>dtable;
public:
	cocos2d::Label* label;
	inline static CResourceTable* getInstance()
	{
		if (instance == nullptr) instance = new CResourceTable();
		return instance;
	}
	~CResourceTable(void);
	inline const std::string GetFileName (const std::string name){return *rtable[name];}
	inline const int GetValue (const std::string name) {return dtable[name];}
};

#endif