#pragma once
#include "Entity.h"

class Door : public CEntity
{
	private:

	public:
	Door(cocos2d::Layer* layer,float posx, float posy);
	~Door(void);
	void openDoor();
	void render(USHORT x, USHORT y);
};

