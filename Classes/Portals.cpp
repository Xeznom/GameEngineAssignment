#include "Portals.h"

void CPortals::update(float delta)
{
	if (existing)	m_Sprite = Portals[type];
	else			m_Sprite = empty;

	if (bTimer)
	{
		timer += 1;
		if (timer > 20) bTimer = false;
	}
	else timer = 0;
}

void CPortals::reset()
{
	existing = connecting = false;
}

CPortals::CPortals(const int type, const Vec2 location)
{
	empty = Sprite::create(GETFILE("Empty"));
	Portals[P_BLUE] = Sprite::create(GETFILE("BluePortal"));
	Portals[P_ORANGE] = Sprite::create(GETFILE("OrangePortal"));

	this->type = type;
	existing = connecting = bTimer = false;

	this->location = location;

	m_Sprite = Portals[type];

	m_Sprite->setPosition(location);

	//portal physics
	const Size size = Size(m_Sprite->getContentSize().width, m_Sprite->getContentSize().height);
	body = PhysicsBody::createBox(size);
	body->setDynamic(false);
	body->setCollisionBitmask(7);
	body->setContactTestBitmask(true);
	m_Sprite->setPhysicsBody(body);
}

CPortals::~CPortals()
{
}

void CPortals::setLoc(const Vec2 loc) 
{
	location = loc;

	const Size size = Size(m_Sprite->getContentSize().width, m_Sprite->getContentSize().height);
	PhysicsBody* newbody = PhysicsBody::createBox(size);
	newbody->setCollisionBitmask(7);
	newbody->setContactTestBitmask(true);
	newbody->setRotationEnable(false);
	newbody->setDynamic(false);

	body = newbody;

	m_Sprite->setPhysicsBody(body);

	m_Sprite->setPosition(loc);
}