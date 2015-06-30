#ifndef __CENEMY_H__
#define __CENEMY_H__

#pragma once

#include "Entity.h"

class CEnemy : public CEntity
{
private:
	static const int STATIC_SPRITE_TAG;
	static const char* filename;
	bool facingLeft;
	float speed;
public:
	CEnemy(Layer*, const Point);
	~CEnemy(void);

	void update (float);
	void Render(Point);

	bool onContactBegin(PhysicsContact&);
};

#endif