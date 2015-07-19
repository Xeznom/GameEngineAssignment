#ifndef __CField_H__
#define __CField_H__

#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#pragma once

#include "Entity.h"

enum M_TILE_TYPES {
	M_EMPTY,
	M_WHITE,
	M_DOOR,
	M_TRAP,
	M_ENEMY,
	M_BUTTON,
	M_MOBILESPIKE,
	M_LASER,
	M_COIN,
	M_TOTAL
	
} ;

static const char* const g_scTileFileName[M_TOTAL] = {
	"empty.png", "white.png", "empty.png", "spike.png","empty.png","empty.png","empty.png", "yellow.png", "Coin.png"
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