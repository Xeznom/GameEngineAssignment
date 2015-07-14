#include "Projectile.h"

Sprite* CProjectile::sprites[];

CProjectile::CProjectile(const short alternate,const Vect velocity)
{
	std::string temp=GETFILE("OrangePortal");
	if (sprites[0] == nullptr)
		sprites[0] = Sprite::create(GETFILE("OrangePortal"));
	if (sprites[1] == nullptr)
		sprites[1] = Sprite::create(GETFILE("BluePortal"));

	m_Sprite = sprites[alternate];

	auto body = PhysicsBody::createBox(Size(m_Sprite->getContentSize().height,m_Sprite->getContentSize().width));
	body->setCollisionBitmask(4);
	body->setContactTestBitmask(true);
	m_Sprite->setPhysicsBody(body);
	body->addMass(10);
	body->setVelocity(velocity);
}

CProjectile::~CProjectile()
{
}

void CProjectile::update(float delta)
{
}