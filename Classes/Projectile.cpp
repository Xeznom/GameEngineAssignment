#include "Projectile.h"

CProjectile::CProjectile(Layer* layer,const short alternate)
{
	speed = GETVALUE("ProjectileSpeed");
	if (alternate == 0)
		m_Sprite = Sprite::create(GETFILE("OrangePortal"));
	else
		m_Sprite = Sprite::create(GETFILE("BluePortal"));
	m_Sprite->setAnchorPoint(Vec2(0.5f,0));

	body = PhysicsBody::createBox(Size(m_Sprite->getContentSize().height
								,m_Sprite->getContentSize().width));
	body->setCollisionBitmask(4);
	body->setContactTestBitmask(true);
	m_Sprite->setPhysicsBody(body);
	layer->addChild(m_Sprite, 0);
	thelayer = layer;
}

void CProjectile::Init(const Vec2 Location,const Vec2 velocity)
{
	m_Sprite->setPosition(Location + velocity);
	body->applyForce(velocity * speed);
}

CProjectile::~CProjectile()
{
}

void CProjectile::update(float delta)
{
}