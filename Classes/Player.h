#ifndef __CPLAYER_H__
#define __CPLAYER_H__

#pragma once

#include "Gun.h"
#include "SimpleAudioEngine.h"

class CPlayer : public CEntity
{
private:
	CocosDenshion::SimpleAudioEngine* audioJump;
	static const int STATIC_SPRITE_TAG;
	bool Jump;
	bool Left, Right;
	float speed;
	int HP;
	PhysicsBody* body;

	Sprite* SLeft;
	Sprite* SRight;
	Sprite* SUp;
public:
	float airtime;
	bool inAir;
	CGun* PortalGun;

	CPlayer(Layer*, const Point);
	~CPlayer(void);
	void Render();

	bool TouchDown (Touch*, Event*);
	void KeyPress(EventKeyboard::KeyCode, Event*);
	void KeyRelease(EventKeyboard::KeyCode, Event*);
	void MouseMove(Event*);
	void MouseDown(Event*);

	inline void setHP(const int Set){ HP = Set; }

	inline const int getHp() { return HP; }

	//void KeyPress (EventKeyboard::KeyCode,Event*);
	//void KeyRelease(EventKeyboard::KeyCode,Event*);
	//void MouseMove(Event*);
	//void MouseDown(Event*);

	void update(float);
	bool onContactBegin(PhysicsContact&);
	void setPos(const Vec2);
};
#endif