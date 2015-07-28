#ifndef __CGEM_H__
#define __CGEM_H__

#pragma once

#include <iostream>
#include "cocos2d.h"


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

	void Init(const E_GEM_TYPES,const int,const int);
	void Render(const int,const int);

	void Update(void);
	void ChangeTexture(const E_GEM_TYPES);

	inline const cocos2d::Sprite* getSprite(void) {return m_Sprite;};

	inline const E_GEM_STATE getState(void) {return m_eState;};
	inline void setState(const E_GEM_STATE eState) {m_eState = eState;}

	inline const E_GEM_TYPES getType(void) {return m_eType;};
	inline void setType(const E_GEM_TYPES newType) {m_eType = newType;}

	inline void setY (const float newY){m_Sprite->setPositionY(newY);};
};

#endif //__GEM_H__