#ifndef __CENTITY_H__
#define __CENTITY_H__

#pragma once

#include "cocos2d.h"
#include "ResourceTable.h"

USING_NS_CC;
#define TILESIZE 28

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
