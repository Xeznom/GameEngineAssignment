#include "Portals.h"

void CPortals::update(float delta)
{
	if (existing)	m_Sprite = Portals[type];
	else			m_Sprite = empty;
}

CPortals::CPortals(const int type, const Point location)
{
	empty = Sprite::create(GETFILE("Empty"));
	Portals[P_BLUE] = Sprite::create(GETFILE("BluePortal"));
	Portals[P_ORANGE] = Sprite::create(GETFILE("OrangePortal"));
	Up = Left = Down = Right = false;

	this->type = type;
	existing = true;
	connecting = false;

	this->location = location;

	m_Sprite = Portals[type];

	m_Sprite->setPosition(location);

	//portal physics
	PhysicsBody* body = PhysicsBody::createCircle(m_Sprite->getContentSize().width);
	body->setDynamic(false);
	body->setCollisionBitmask(7);
	body->setContactTestBitmask(true);
	m_Sprite->setPhysicsBody(body);
}

CPortals::~CPortals()
{
}

void CPortals::setLoc(Point loc) 
{
	location = loc;
	m_Sprite->setPosition(loc);
}

int CPortals::getDirection()
{
	if (Up) return 1;
	else if (Down) return 2;
	else if (Left) return 3;
	else if (Right) return 4;
	else return 0;
};