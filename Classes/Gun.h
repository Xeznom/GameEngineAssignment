#ifndef __CGUN_H__
#define __CGUN_H__

#pragma once

#include "Projectile.h"

class CGun : public CEntity
{
private:
	CProjectile* projectile[2]; //Two projectiles?
	const Sprite* PlayerSprite;
	bool Left;
public:
	float Offset;
	CGun(Layer*, const Point, const Sprite*);
	~CGun(void);
	void update(float);
	void MouseMove(Event*);
	void MouseDown(Event*);
};

#endif