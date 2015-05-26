#ifndef __CGUN_H__
#define __CGUN_H__

#pragma once

#include "Entity.h"

class CGun : public CEntity
{
private:
	static const char* filename;
	bool Left;
public:
	float Offset;
	CGun(void);
	~CGun(void);
	void update (float delta);
	void MouseMove(cocos2d::Event*);
};

#endif