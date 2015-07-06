#pragma once
#include "Entity.h"

class Button : public CEntity
{
	private:

	public:
	Button(cocos2d::Layer* layer,float posx, float posy);
	~Button(void);
	void pressed();
	void render(USHORT x, USHORT y);
};

