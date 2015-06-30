#ifndef __CPLAYER_H__
#define __CPLAYER_H__

#pragma once

#include "Gun.h"

class CPlayer : public CEntity
{
private:
	bool Up,Down,Left,Right;
	float speed;
public:
	CGun* PortalGun;

	CPlayer(cocos2d::Layer*, const cocos2d::Point);
	~CPlayer(void);
	void Render();

	void KeyPress (cocos2d::EventKeyboard::KeyCode,cocos2d::Event*);
	void KeyRelease(cocos2d::EventKeyboard::KeyCode,cocos2d::Event*);
	void MouseMove(cocos2d::Event*);
	void MouseDown(cocos2d::Event*);

	void update(float);
	bool onContactBegin(PhysicsContact&);
};

#endif