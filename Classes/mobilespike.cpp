#include "mobilespike.h"

CMobileSpike :: CMobileSpike(cocos2d::Layer* layer,float posx,float posy)
{
	movementCounter = 1;

	x = posx;
	y = posy;

	m_Sprite = cocos2d::Sprite::create("CloseNormal.png");
	//m_Sprite->Sprite::setTexture("CloseNormal.png");
	m_Sprite->setScale(10.0f);
	m_Sprite->Sprite::setPosition(Point(x,y));

	auto body = PhysicsBody::createBox(Size(m_Sprite->getContentSize().width,m_Sprite->getContentSize().width));
	body->setCollisionBitmask(2);
	body->setContactTestBitmask(true);
	body->setDynamic(false);
	m_Sprite->setPhysicsBody(body);

	Render(x,y);
	layer->addChild(m_Sprite,0);
}

CMobileSpike :: ~CMobileSpike()
{
	
}

void CMobileSpike :: Render(USHORT x, USHORT y)
{
	//Size visibleSize = Director::getInstance()->getVisibleSize();
	//float f_posX = visibleSize.width*0.5f + (x - 10);
	//float f_posY = visibleSize.height - (y);
	//m_Sprite->setPosition( Point(f_posX, f_posY) );
	Point temp = m_Sprite->getPosition();
}

void CMobileSpike :: update(float delta)
{
	Vec2 loc = m_Sprite->getPosition();
	loc.y = loc.y + (5 * movementCounter);
	m_Sprite->setPosition(loc);
}

void CMobileSpike :: changedirection()
{
	movementCounter = -movementCounter;
}