#include "Projectile.h"

const char* CProjectile::filename[] = { "OrangeProjectile.png", "BlueProjectile.png" };

CProjectile::CProjectile()
{
	PhysicsBody* body = PhysicsBody::createBox(Size(m_Sprite->getContentSize().width,m_Sprite->getContentSize().width));
	body->setCollisionBitmask(4);
	body->setContactTestBitmask(true);
	m_Sprite->setPhysicsBody(body);
}

CProjectile::~CProjectile()
{
}

void CProjectile::update(float delta)
{

}