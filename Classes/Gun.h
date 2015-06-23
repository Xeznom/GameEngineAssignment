#ifndef __CGUN_H__
#define __CGUN_H__

#pragma once

#include "Entity.h"

class CGun : public CEntity
{
private:
	static const char* filename;
	Sprite* PlayerSprite;
	bool Left;
public:
	Label* label;
	float Offset;
	CGun(Sprite*);
	~CGun(void);
	void update (float delta);
	void MouseMove(cocos2d::Event*);
};

#endif