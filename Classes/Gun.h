#ifndef __CGUN_H__
#define __CGUN_H__

#pragma once

#include "Projectile.h"

class CGun : public CEntity
{
private:
	static const char* filename;
	CProjectile* projectile[2]; //Two projectiles?
	Sprite* PlayerSprite;
	bool Left;
public:
	float Offset;
	CGun(Sprite*);
	~CGun(void);
	void update(float);
	void MouseDown(cocos2d::Event*);
};

#endif