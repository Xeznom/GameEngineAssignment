#ifndef __CPORTALS_H__
#define __CPORTALS_H__

#pragma once

#include "Entity.h"

enum P_PORTALS_TYPES
{
	P_ORANGE,
	P_BLUE,
	P_TOTAL
};

class CPortals : public CEntity
{
private:
	Vec2 location;

	PhysicsBody* body;

	int type,timer;
	Sprite* empty;
	Sprite* Portals[P_TOTAL];

public:
	bool connecting;
	bool bTimer;
	
	CPortals(Layer* layer, const int, const Vec2);
	~CPortals(void);

	void update(float);
	
	void setLoc(const Vec2);
	inline const Vec2 getLoc(void) { return location; };
};

#endif