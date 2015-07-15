#include "laser.h"

CLaser :: CLaser(cocos2d::Layer* layer,float posx,float posy)
{
	index = 0;//default index

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

CLaser :: ~CLaser()
{
	
}

void CLaser :: Render(USHORT x, USHORT y)
{
	//Size visibleSize = Director::getInstance()->getVisibleSize();
	//float f_posX = visibleSize.width*0.5f + (x - 10);
	//float f_posY = visibleSize.height - (y);
	//m_Sprite->setPosition( Point(f_posX, f_posY) );
	Point temp = m_Sprite->getPosition();
}

void CLaser::LaserOff()
{
	m_Sprite->setTexture(CCTextureCache::sharedTextureCache()->addImage("empty.png"));
	m_Sprite->getPhysicsBody()->setCollisionBitmask(3);
}

int CLaser :: GetIndex()
{
	return index;
}

void CLaser :: SetIndex(int index)
{
	this->index = index;
}

