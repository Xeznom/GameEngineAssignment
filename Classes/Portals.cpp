#include "Portals.h"


CPortals::CPortals(int type, Point location)
{
	Up = Left = Down = Right = false;

	existing = true;
	connecting = false;

	this->location = location;

	m_Sprite = Sprite::create(filename[type]);
	m_Sprite->setPosition(location);

	//portal physics
	auto body = PhysicsBody::createCircle(m_Sprite->getContentSize().width);
	body->setDynamic(false);
	body->setCollisionBitmask(3);
	body->setContactTestBitmask(true);
	m_Sprite->setPhysicsBody(body);
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

int CPortals::getDirection() {
	if (Up)
		return 1;
	if (Down)
		return 2;
	if (Left)
		return 3;
	if (Right)
		return 4;
};