#ifndef __CENEMY_H__
#define __CENEMY_H__

#pragma once

#include "Enemy.h"
#include "Entity.h"

static const char* const g_EnemyFileName = {
	"spike.png"
};


class CEnemy : public CEntity
{
private:

	bool facingLeft;
	float speed;
public:

	CEnemy(Layer*, const Point);
	~CEnemy(void);

	void update (float delta);

	bool onContactBegin(PhysicsContact& contact);
};

#endif