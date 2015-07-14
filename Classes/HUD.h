#ifndef __CHUD_H__
#define __CHUD_H__

#pragma once

#include "Entity.h"

class CHUD : public cocos2d::Layer
{
private:
	Label* message;
public:
	CHUD(String, Vec2, int, int);
	~CHUD();

	inline Label* GetHUD() { return message; };
};

#endif