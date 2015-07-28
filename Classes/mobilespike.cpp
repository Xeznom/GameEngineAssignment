#include "mobilespike.h"

CMobileSpike :: CMobileSpike(cocos2d::Layer* layer,const float posx,const float posy)
{
	movementCounter = 1;

	x = posx; y = posy;

	const std::string filename = GETFILE("MobileSpike");
	m_Sprite = Sprite::create(filename);
	//m_Sprite->setScale(0.01f);
	m_Sprite->Sprite::setPosition(Point(x,y));

	const Size size = Size(m_Sprite->getContentSize().width, m_Sprite->getContentSize().width);
	PhysicsBody* body = PhysicsBody::createBox(size);
	body->setCollisionBitmask(11);
	body->setContactTestBitmask(true);
	//body->setDynamic(false);
	body->setRotationEnable(false);
	body->setGravityEnable(false);
	body->setMass(1.0f);
	m_Sprite->setPhysicsBody(body);

	Render(posx,posy);

	layer->addChild(m_Sprite,0);
	thelayer = layer;
}

CMobileSpike :: ~CMobileSpike()
{
	
}

void CMobileSpike :: Render(const int x,const int y)
{
	const Size visibleSize = Director::getInstance()->getVisibleSize();
	const float f_posX = visibleSize.width*0.5f + (x - 10) * TileSize * 1.5f;
	const float f_posY = visibleSize.height - (y)* TileSize * 1.5f;
	this->m_Sprite->setPosition( Point(f_posX, f_posY) );
}

void CMobileSpike :: update(float delta)
{
	//Vec2 loc = m_Sprite->getPosition();
	//loc.y = loc.y + (10 * delta * movementCounter);
	PhysicsBody* body = m_Sprite->getPhysicsBody();
	body->applyImpulse(Vec2(0,500 * delta * movementCounter));
	m_Sprite->setPhysicsBody(body);
	//m_Sprite->setPosition(loc);
}

void CMobileSpike :: changedirection()
{
	movementCounter = -movementCounter;
}