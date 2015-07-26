#ifndef __CResourceTable_H__
#define __CResourceTable_H__

#pragma once

#include "cocos2d.h"
#include <map>
#include <string>
#include <thread>

#define GETFILE(X) CResourceTable::getInstance()->GetFileName(X)
#define GETMAP(X) CResourceTable::getInstance()->GetMap(X)
#define GETMUSIC(X) CResourceTable::getInstance()->GetMusic(X)
#define GETEXTURE(X) CResourceTable::getInstance()->GetTexture(X)
#define GETVALUE(X) CResourceTable::getInstance()->GetValue(X)

class CResourceTable
{
private:
	static CResourceTable* instance;
	CResourceTable(void);
	std::map<std::string,std::string*> rtable;

	std::map<std::string, std::string*> map_table;
	std::map<std::string, std::string*> music_table;
	std::map<std::string, std::string*> texture_table;

	std::map<std::string,int>data_table;
public:
	cocos2d::Label* label;
	inline static CResourceTable* getInstance()
	{
		if (instance == nullptr) instance = new CResourceTable();
		return instance;
	}
	~CResourceTable(void);
	inline const std::string GetFileName (const std::string name) {return *rtable[name];}
	inline const std::string GetMap(const std::string name){ return *map_table[name]; }
	inline const std::string GetMusic(const std::string name){ return *map_table[name]; }
	inline const std::string GetTexture(const std::string name){ return *map_table[name]; }
	inline const int GetValue(const std::string name) { return data_table[name]; }
};

#endif