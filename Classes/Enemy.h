#ifndef __CENEMY_H__
#define __CENEMY_H__

#pragma once

#include "Entity.h"

class CEnemy : public CEntity
{
private:
	static const int STATIC_SPRITE_TAG;
	bool facingLeft;
	float speed;
public:
	CEnemy(Layer*, const Point);
	~CEnemy(void);

	void update (float);
	void Render(const Point);

	bool onContactBegin(const PhysicsContact&);
};

#endif