#include "Portals.h"

const char* CPortals::filename[] = { "blueP.png", "orangeP.png" };

void CPortals::update(float delta)
{
	if (existing)
		m_Sprite->setTexture(CCTextureCache::sharedTextureCache()->addImage(filename[type]));
	else
		m_Sprite->setTexture(CCTextureCache::sharedTextureCache()->addImage("empty.png"));
}

CPortals::CPortals(int type, Point location)
{
	Up = Left = Down = Right = false;

	this->type = type;
	existing = true;
	connecting = false;

	this->location = location;

	m_Sprite = Sprite::create(filename[type]);
	m_Sprite->setPosition(location);

	//portal physics
	auto body = PhysicsBody::createCircle(m_Sprite->getContentSize().width);
	body->setDynamic(false);
	body->setCollisionBitmask(7);
	body->setContactTestBitmask(true);
	m_Sprite->setPhysicsBody(body);
}

CPortals::~CPortals()
{
}

void CPortals::setLoc(Point loc) {
	location = loc;
	m_Sprite->setPosition(loc);
}

int CPortals::getDirection() {
	if (Up) return 1;
	else if (Down) return 2;
	else if (Left) return 3;
	else if (Right) return 4;
};