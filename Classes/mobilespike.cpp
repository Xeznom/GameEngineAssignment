#include "mobilespike.h"

CMobileSpike :: CMobileSpike(cocos2d::Layer* layer,float posx,float posy)
{
	movementCounter = 1;

	x = posx;
	y = posy;

	std::string filename = GETFILE("MobileSpike");
	m_Sprite = Sprite::create(filename);
	//m_Sprite->setScale(0.01f);
	m_Sprite->Sprite::setPosition(Point(x,y));

	auto body = PhysicsBody::createBox(Size(m_Sprite->getContentSize().width,m_Sprite->getContentSize().width));
	body->setCollisionBitmask(11);
	body->setContactTestBitmask(true);
	//body->setDynamic(false);
	body->setRotationEnable(false);
	body->setGravityEnable(false);
	m_Sprite->setPhysicsBody(body);

	Render(posx,posy);

	layer->addChild(m_Sprite,0);
	thelayer = layer;
}

CMobileSpike :: ~CMobileSpike()
{
	
}

void CMobileSpike :: Render(USHORT x, USHORT y)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	float f_posX = visibleSize.width*0.5f + (x - 10) * TileSize * 1.5f;
	float f_posY = visibleSize.height - (y)* TileSize * 1.5f;
	this->m_Sprite->setPosition( Point(f_posX, f_posY) );
}

void CMobileSpike :: update(float delta)
{
	//Vec2 loc = m_Sprite->getPosition();
	//loc.y = loc.y + (10 * delta * movementCounter);
	auto body = m_Sprite->getPhysicsBody();
	body->applyImpulse(Vec2(0,1000 * delta * movementCounter));
	m_Sprite->setPhysicsBody(body);
	//m_Sprite->setPosition(loc);
}

void CMobileSpike :: changedirection()
{
	movementCounter = -movementCounter;
}