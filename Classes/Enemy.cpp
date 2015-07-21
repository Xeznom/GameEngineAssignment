#include "Enemy.h"

const int CEnemy::STATIC_SPRITE_TAG = 0;

CEnemy::CEnemy(Layer* layer, const Point pos)
{
	facingLeft = false;
	speed = GETVALUE("EnemyWalkSpeed");
	std::string filename = GETFILE("Enemy");
	m_Sprite = cocos2d::Sprite::create(filename);

	//player physics
	auto body = PhysicsBody::createBox(Size(m_Sprite->getContentSize().width,m_Sprite->getContentSize().height));
	body->setMass(GETVALUE("EnemyMass"));
	body->setCollisionBitmask(8);//changed to 8 temporally
	body->setContactTestBitmask(true);
	body->setRotationEnable(false);
	m_Sprite->setPhysicsBody(body);

	Render(pos);

	layer->addChild(m_Sprite,0);
	thelayer = layer;
}


CEnemy::~CEnemy(void)
{}

void CEnemy::update (float delta)
{
	Vec2 loc = m_Sprite->getPosition();

	if (facingLeft)
		loc.x += speed * delta;
	else
		loc.x -= speed * delta;

	m_Sprite->setPosition(loc);
}

void CEnemy::Render(Point location)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	float f_posX = visibleSize.width*0.5f + (location.x - 10) * TileSize * 1.5;
	float f_posY = visibleSize.height - (location.y)* TileSize * 1.5;
	m_Sprite->setPosition( Point(f_posX, f_posY) );
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