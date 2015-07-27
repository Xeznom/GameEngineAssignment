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
	CHUD(const std::string&,const float,const Vec2,const int,const int);
	~CHUD();

	void Update(int);
	void initOptions(const std::string&, const float, const Vec2, const int, const int);
	void valueupdate(const int);
	virtual void draw(const Renderer*, const Mat4& ,const bool);
};

#endif