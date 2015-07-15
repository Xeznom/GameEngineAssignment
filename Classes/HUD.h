#ifndef __CHUD_H__
#define __CHUD_H__

#pragma once

#include "Entity.h"

class CHUD : public cocos2d::LayerColor
{
private:
	//Label* message;
	cocos2d::LabelBMFont* _messageLabel;
public:
	CHUD(const std::string&, Vec2, int, int);
	~CHUD();

	void initOptions(const std::string& _message, Vec2 pos, int topbottom, int leftright);

	virtual void draw(cocos2d::Renderer * renderer, const cocos2d::Mat4 & transform, bool transformUpdated);

	//inline Label* GetHUD() { return message; };
};

#endif