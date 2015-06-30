#ifndef __CField_H__
#define __CField_H__

#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#pragma once

#include "Entity.h"

enum M_TILE_TYPES {
	M_WHITE,
	M_EMPTY,
	M_DOOR,
	M_TRAP,
	M_TOTAL
} ;

static const char* const g_scTileFileName[M_TOTAL] = {
	"empty.png", "white.png", "door.png", "spike.png"
};

class CField : public CEntity
{
private:

	int tiles;

public:
	CField(int, USHORT, USHORT);
	~CField(void);

	void Render(USHORT, USHORT);

	bool LoadFile(const string mapName);
	//cocos2d::Sprite* getSprite(void) {return m_Sprite;};

};

#endif //__CField_H__