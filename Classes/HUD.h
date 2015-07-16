#ifndef __CHUD_H__
#define __CHUD_H__

#pragma once

#include "Entity.h"

class CHUD : public cocos2d::Layer
{
private:
	cocos2d::Label* _messageLabel;
public:
	CHUD(const std::string&, Vec2, int, int);
	~CHUD();

	void initOptions(const std::string&,Vec2,int,int);

	virtual void draw(Renderer*, const Mat4& , bool);
};

#endif