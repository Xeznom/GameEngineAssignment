#ifndef __CENTITY_H__
#define __CENTITY_H__

#pragma once
#define TILESIZE 28

#include "cocos2d.h"
#include "ResouceTable.h"
USING_NS_CC;

class CEntity
{
public:
	cocos2d::Sprite* m_Sprite;
	float x, y;

	CEntity(void);
	virtual ~CEntity(void);
	virtual void update(float){};
};

#endif
