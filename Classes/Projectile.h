#ifndef __CPROJECTILE_H__
#define __CPROJECTILE_H__

#pragma once

#include "Entity.h"

class CProjectile : public CEntity
{
private:
	PhysicsBody* body;
	Sprite* sprites[2];
	float speed;
public:
	CProjectile();
	~CProjectile();
	void update(float);
	void Init(const short alternate,const Vect velocity);
};

#endif