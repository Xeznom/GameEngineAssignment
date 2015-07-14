#include "Projectile.h"

CProjectile::CProjectile()
{
	sprites[0]=sprites[1]=nullptr;
	std::string temp=GETFILE("OrangePortal");
	m_Sprite=nullptr;
	body=nullptr;
}

void CProjectile::Init(const short alternate,const Vect velocity)
{
	sprites[0] = cocos2d::Sprite::create("orangeP.png");
	sprites[1] = cocos2d::Sprite::create(GETFILE("BluePortal"));
	m_Sprite = sprites[alternate];

	body = PhysicsBody::createBox(Size(m_Sprite->getContentSize().height,m_Sprite->getContentSize().width));
	body->setCollisionBitmask(4);
	body->setContactTestBitmask(true);
	body->addMass(10);
	body->setVelocity(velocity);
	m_Sprite->setPhysicsBody(body);
}

CProjectile::~CProjectile()
{
}

void CProjectile::update(float delta)
{
}