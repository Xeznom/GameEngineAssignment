#ifndef __CHUD_H__
#define __CHUD_H__

#pragma once

#include "Entity.h"

class CHUD : public cocos2d::LayerColor
{
private:
	Label* message;
public:
	CHUD();
	~CHUD();

	CHUD* createHUD(String, Point);

	Label* GetHUD() { return message; };
};

#endif