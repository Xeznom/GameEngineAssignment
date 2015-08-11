#ifndef __CPLAYER_H__
#define __CPLAYER_H__

#pragma once

#include "Gun.h"

static const char* const playerFrames[6] = {
	"Player.png", "Player.png", "Player.png", "Player1.png", "Player1.png", "Player1.png"
};

class CPlayer : public CEntity
{
private:
	CocosDenshion::SimpleAudioEngine* audioJump;
	static const int STATIC_SPRITE_TAG;
	bool Jump;
	bool Left, Right;
	float speed;
	int HP;
	int frames;
	PhysicsBody* body;

	Sprite* SLeft;
	Sprite* SRight;
	Sprite* SUp;
public:
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