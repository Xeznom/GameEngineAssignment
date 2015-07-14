#ifndef __CPROJECTILE_H__
#define __CPROJECTILE_H__

#pragma once

#include "Entity.h"

class CProjectile : public CEntity
{
private:
	PhysicsBody* body;
	float speed;
public:
	CProjectile(Layer*,const short);
	~CProjectile();
	void update(float);
	void Init(const Vec2, const Vec2);
};

#endif