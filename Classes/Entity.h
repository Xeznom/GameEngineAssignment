#ifndef __CENTITY_H__
#define __CENTITY_H__

#pragma once

#include "cocos2d.h"

class CEntity
{
public:
	cocos2d::Sprite* m_Sprite;

	CEntity(void);
	virtual ~CEntity(void);
};

#endif
