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
public:
	CGun* PortalGun;

	CPlayer(Layer*, const Point);
	~CPlayer(void);
	void Render();

	void KeyPress (EventKeyboard::KeyCode,Event*);
	void KeyRelease(EventKeyboard::KeyCode,Event*);
	void MouseMove(Event*);
	void MouseDown(Event*);

	void update(float);
	bool onContactBegin(PhysicsContact&);
};

#endif