#ifndef __CGUN_H__
#define __CGUN_H__

#pragma once

#include "Projectile.h"

class CGun : public CEntity
{
private:
	const Sprite* PlayerSprite;
	bool Left;
public:
	short Alternate;
	CProjectile* projectile[2]; //Two projectiles?
	float Offset;
	CGun(Layer*, const Point, const Sprite*);
	~CGun(void);
	void update(float);
	void MouseMove(Event*);
	void MouseDown(Event*);
};

#endif