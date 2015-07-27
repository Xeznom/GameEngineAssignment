#ifndef __CSPIKES_H__
#define __CSPIKES_H__

#pragma once
#include "Entity.h"

class CSpikes : public CEntity
{
	public:
	CSpikes(cocos2d::Layer*,const float,const float);
	~CSpikes(void);

	void Render(const USHORT,const USHORT);
};
#endif