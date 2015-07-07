#ifndef __CPROJECTILE_H__
#define __CPROJECTILE_H__

#pragma once

#include "Entity.h"

class CProjectile : public CEntity
{
private:
	PhysicsBody* body;
	static Sprite* sprites[2];
	float speed;
public:
	CProjectile(short, Vect);
	~CProjectile();
	void update(float);
};

#endif