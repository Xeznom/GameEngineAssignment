#pragma once
#include "Entity.h"

class Button : public CEntity
{
	private:
	int index;//keeps track to tell which object it interacts with
	public:
	Button(cocos2d::Layer* layer,float posx, float posy);
	~Button(void);
	int GetIndex();
	void SetIndex(int index);
	void pressed();
	void render(USHORT x, USHORT y);
};

