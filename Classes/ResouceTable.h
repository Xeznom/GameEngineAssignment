#ifndef __CRESROUCETABLE_H__
#define __CRESROUCETABLE_H__

#pragma once

#include <map>

class CResouceTable
{
private:
	static CResouceTable* instance;
	CResouceTable(void);
	static const char* filename;
	std::map<const char*,const char*> table;
public:
	inline static CResouceTable* getInstance()
	{
		if (instance == nullptr) instance = new CResouceTable();
		return instance;
	}
	~CResouceTable(void);
	inline const char* GetFileName (const char* name){return table[name];}
};

#endif