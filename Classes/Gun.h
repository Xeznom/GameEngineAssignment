#ifndef __CGUN_H__
#define __CGUN_H__

#pragma once

#include "Projectile.h"
#include "SimpleAudioEngine.h"

class CGun : public CEntity
{
private:
	const Sprite* PlayerSprite;
	bool Left;
public:
	bool Fired;
	short Current;
	CProjectile* projectile[2]; //Two projectiles?
	float Offset;
	CGun(Layer*, const Point, const Sprite*);
	~CGun(void);
	void update(float);
	void MouseMove(Event*);
	void MouseDown(Event*);
};

#endif