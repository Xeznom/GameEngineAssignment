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
	auto body = PhysicsBody::createCircle(m_Sprite->getContentSize().width/2);
	body->setDynamic(false);
	body->setCollisionBitmask(1);
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