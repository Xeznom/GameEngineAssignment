#ifndef __CENTITY_H__
#define __CENTITY_H__

#pragma once

#include "cocos2d.h"
USING_NS_CC;

class CEntity
{
public:
	cocos2d::Sprite* m_Sprite;
	float x, y;

	CEntity(void);
	virtual ~CEntity(void);
};

#endif
