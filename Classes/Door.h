#pragma once
#include "Entity.h"

class Door : public CEntity
{
	private:
	int index;
	public:
	Door(cocos2d::Layer* layer,float posx, float posy);
	~Door(void);
	int GetIndex();
	void SetIndex(int index);
	void openDoor();
	void render(USHORT x, USHORT y);
};

