#ifndef __CPORTALS_H__
#define __CPORTALS_H__

#pragma once

#include "Entity.h"

enum P_PORTALS_TYPES {
	P_BLUE,
	P_ORANGE,
	P_TOTAL
};

static const char* const filename[P_TOTAL] = {
	"blueP.png", "orangeP.png"
};

class CPortals : public CEntity
{
private:
	Point location;

	bool existing, connecting;
	bool Up, Down, Left, Right;

public:
	CPortals(int, Point);
	~CPortals(void);

	void update();

	void setConnection(bool status) { connecting = status; };
	
	void setLoc(Point loc);
	Point getLoc() { return location; };

	int getDirection();
	bool getExist() { return existing; };
	bool getConnection() { return connecting; };
};


#endif