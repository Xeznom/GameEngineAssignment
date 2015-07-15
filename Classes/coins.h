#pragma once
#include "Entity.h"

class CCoin : public CEntity
{
	private:
	int index;
	public:
	CCoin(cocos2d::Layer* layer,float posx, float posy);
	~CCoin(void);
	int GetIndex();
	void SetIndex(int index);
	void PickedUp();
	void render(USHORT x, USHORT y);
};

