#ifndef __CPLAYER_H__
#define __CPLAYER_H__

#pragma once

#include "Gun.h"

class CPlayer : public CEntity
{
private:
	static const int STATIC_SPRITE_TAG;
	bool Jump;
	bool Left,Right;
	float speed;
	int HP;
public:
	CGun* PortalGun;

	CPlayer(Layer*, const Point);
	~CPlayer(void);
	void Render();

<<<<<<< HEAD
	void KeyPress (cocos2d::EventKeyboard::KeyCode,cocos2d::Event*);
	void KeyRelease(cocos2d::EventKeyboard::KeyCode,cocos2d::Event*);
	void MouseMove(cocos2d::Event*);
	void MouseDown(cocos2d::Event*);
	void setHP(int Set);
	int getHp();
=======
	void KeyPress (EventKeyboard::KeyCode,Event*);
	void KeyRelease(EventKeyboard::KeyCode,Event*);
	void MouseMove(Event*);
	void MouseDown(Event*);
>>>>>>> origin/master

	void update(float);
	bool onContactBegin(PhysicsContact&);
};

#endif