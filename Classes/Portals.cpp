#include "Portals.h"


CPortals::CPortals(int type, Point location)
{
	Up = Left = Down = Right = false;

	existing = true;
	connecting = false;

	this->location = location;

	m_Sprite = Sprite::create(filename[type-1]);
	m_Sprite->setPosition(location);
}

CPortals::~CPortals()
{
}


void CPortals::update() {

}

void CPortals::setLoc(Point loc) {
	location = loc;
	m_Sprite->setPosition(loc);
}