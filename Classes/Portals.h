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
	Point location;

	PhysicsBody* body;

	int type;
	int timer;
	bool bTimer;
	bool existing, connecting;
	bool Up, Down, Left, Right;
	Sprite* empty;
	Sprite* Portals[P_TOTAL];
public:
	CPortals(const int, const Point);
	~CPortals(void);

	void update(float);

	inline void setConnection(const bool status) { connecting = status; };
	
	void setLoc(Point loc);
	void setExist(bool setting) { existing = setting; };
	inline const Point getLoc() const { return location; };

	int getDirection();
	inline const bool getExist() const { return existing; };
	inline const bool getConnection() const { return connecting; };
};

#endif