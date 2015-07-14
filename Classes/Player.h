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
	PhysicsBody* body;
public:
	bool inAir;
	CGun* PortalGun;

	CPlayer(Layer*, const Point);
	~CPlayer(void);
	void Render();

	void KeyPress (cocos2d::EventKeyboard::KeyCode,cocos2d::Event*);
	void KeyRelease(cocos2d::EventKeyboard::KeyCode,cocos2d::Event*);
	void MouseMove(cocos2d::Event*);
	void MouseDown(cocos2d::Event*);
	void setHP(const int Set);
	const int getHp() const;

	void setPos(const Point);
	//void KeyPress (EventKeyboard::KeyCode,Event*);
	//void KeyRelease(EventKeyboard::KeyCode,Event*);
	//void MouseMove(Event*);
	//void MouseDown(Event*);

	void update(float);
	bool onContactBegin(PhysicsContact&);
};

#endif