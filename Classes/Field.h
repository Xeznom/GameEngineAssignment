#ifndef __CField_H__
#define __CField_H__

#pragma once

#include "Entity.h"

enum M_TILE_TYPES {
	M_WHITE,
	M_EMPTY,
	M_TOTAL
};

static const char* const g_scTileFileName[M_TOTAL] = {
	"white.png", "Empty.png"
};

class CField : public CEntity
{
private:

	M_TILE_TYPES tiles;

public:
	CField(void);
	~CField(void);

	void Init(M_TILE_TYPES, USHORT, USHORT);
	void Render(USHORT, USHORT);

	cocos2d::Sprite* getSprite(void) {return m_Sprite;};

};

#endif //__CField_H__