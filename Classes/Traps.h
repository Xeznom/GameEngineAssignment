#ifndef __CTRAPS_H__
#define __CTRAPS_H__

#pragma once
#include "Entity.h"

class CTraps : public CEntity
{
public:
	CTraps(cocos2d::Layer*,const float,const float);
	~CTraps(void);

	void Render(const USHORT,const USHORT);
};
#endif