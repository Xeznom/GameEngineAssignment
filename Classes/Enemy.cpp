#include "Enemy.h"

const int CEnemy::STATIC_SPRITE_TAG = 0;
const char* CEnemy::filename = "spike.png";

CEnemy::CEnemy(Layer* layer, const Point pos)
{
	facingLeft = false;
	speed = 50.0f;
	if (m_Sprite == nullptr) m_Sprite = cocos2d::Sprite::create(filename);

	//player physics
	auto body = PhysicsBody::createCircle(m_Sprite->getContentSize().width);
	body->setMass(10);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(true);
	m_Sprite->setPhysicsBody(body);

	m_Sprite->setScale(0.15f);
	m_Sprite->setPosition(pos);

	layer->addChild(m_Sprite,0);
}


CEnemy::~CEnemy(void)
{
}

void CEnemy::update (float delta)
{
	Vec2 loc = m_Sprite->getPosition();

	if (facingLeft)
		loc.x += speed * delta;
	else
		loc.x -= speed * delta;

	m_Sprite->setPosition(loc);
}

bool CEnemy::onContactBegin(PhysicsContact& contact)
{
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();
    if (nodeA && nodeB)
    {
        if (nodeA->getTag() == STATIC_SPRITE_TAG)
        {
            nodeB->removeFromParentAndCleanup(true);
        }
        else if (nodeB->getTag() == STATIC_SPRITE_TAG)
        {
            nodeA->removeFromParentAndCleanup(true);
        }
    }

    //bodies can collide
    return true;
}