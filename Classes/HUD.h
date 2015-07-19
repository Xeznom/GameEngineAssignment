#ifndef __CHUD_H__
#define __CHUD_H__

#pragma once

#include "Entity.h"

class CHUD : public cocos2d::Layer
{
private:
	cocos2d::Label* _messageLabel;
	cocos2d::Label* _valuemessageLabel;
public:
	CHUD(const std::string&,float, Vec2, int, int);
	~CHUD();

	void initOptions(const std::string&,float,Vec2,int,int);
	void valueupdate(float);
	virtual void draw(Renderer*, const Mat4& , bool);
};

#endif