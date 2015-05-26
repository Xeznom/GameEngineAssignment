#ifndef __CPLAYER_H__
#define __CPLAYER_H__

#pragma once

#include "Entity.h"

class CPlayer : public CEntity
{
private:
	static const char* filename;

	bool Up,Down,Left,Right;
	float speed;

public:
	CPlayer(const cocos2d::Point);
	~CPlayer(void);

	void KeyPress (cocos2d::EventKeyboard::KeyCode,cocos2d::Event*);
	void KeyRelease(cocos2d::EventKeyboard::KeyCode,cocos2d::Event*);
	void MouseMove(cocos2d::Event*);

	void update (float delta);
};

#endif