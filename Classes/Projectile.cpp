#include "Projectile.h"

const char* CProjectile::filename[] = { "Projectile.png", "Projectile.png" };

CProjectile::CProjectile()
{
	auto body = PhysicsBody::createBox(Size(m_Sprite->getContentSize().width,m_Sprite->getContentSize().width));
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