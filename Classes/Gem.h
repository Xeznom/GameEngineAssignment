#ifndef __GEM_H__
#define __GEM_H__

#include <iostream>
#include "cocos2d.h"

#pragma once

enum E_GEM_TYPES {
	E_BLUE,
	E_GREEN,
	E_ORANGE,
	E_PURPLE,
	E_RED,
	E_WHITE,
	E_YELLOW,
	E_EMPTY,
	E_TOTAL
};

enum E_GEM_STATE {
	E_GEM_NORMAL,
	E_GEM_REMOVE,
	E_GEM_MOVE,
	E_GEM_TOTAL
};

static const char* const g_scGemFileName[E_TOTAL] = {
	"blue.png", "green.png", "orange.png", "purple.png", "red.png", "white.png", "yellow.png", "empty.png"};


class cGem
{
	cocos2d::Action* m_Action;
	bool m_bDrop;

	cocos2d::Sprite* m_Sprite;
	E_GEM_TYPES m_eType;
	E_GEM_STATE m_eState;

public:

	cGem(void);
	~cGem(void);

	void Init(E_GEM_TYPES, USHORT, USHORT);
	void Render(USHORT, USHORT);

	void Update(void);
	void ChangeTexture(E_GEM_TYPES);

	cocos2d::Sprite* getSprite(void) {return m_Sprite;};

	E_GEM_STATE getState(void) {return m_eState;};
	void setState(E_GEM_STATE eState) {m_eState = eState);

	E_GEM_TYPES getType(void) {return m_eType;};
	void setType(E_GEM_TYPES newType) {m_eType = newType);

	void setY (float newY)
	{
		m_Sprite->setPositionY(newY);
	};
};

#endif //__GEM_H__