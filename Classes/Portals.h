#ifndef __CPORTALS_H__
#define __CPORTALS_H__

#pragma once

#include "Entity.h"

enum P_PORTALS_TYPES
{
	P_BLUE,
	P_ORANGE,
	P_TOTAL
};

class CPortals : public CEntity
{
private:
	Vec2 location;

	PhysicsBody* body;

	int type,timer;
	bool existing, connecting;
	Sprite* empty;
	Sprite* Portals[P_TOTAL];

public:
	bool bTimer;
	
	CPortals(const int, const Vec2);
	~CPortals(void);

	void update(float);
	void reset(void);
	
	void setLoc(const Vec2);
	inline const Vec2 getLoc(void) { return location; };

	inline void setExist(const bool setting) { existing = setting; };
	inline void setConnection(const bool status) { connecting = status; };

	inline const bool getExist(void) { return existing; };
	inline const bool getConnection(void) { return connecting; };
};

#endif