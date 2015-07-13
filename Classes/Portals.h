#ifndef __CPORTALS_H__
#define __CPORTALS_H__

#pragma once

#include "Entity.h"

enum P_PORTALS_TYPES {
	P_BLUE,
	P_ORANGE,
	P_TOTAL
};

class CPortals : public CEntity
{
private:
	static const char* filename[P_TOTAL];
	Point location;

	int type;
	bool existing, connecting;
	bool Up, Down, Left, Right;

public:
	CPortals(int, Point);
	~CPortals(void);

	void update(float);

	void setConnection(bool status) { connecting = status; };
	
	void setLoc(Point loc);
	Point getLoc() { return location; };

	int getDirection();
	bool getExist() { return existing; };
	bool getConnection() { return connecting; };
};


#endif