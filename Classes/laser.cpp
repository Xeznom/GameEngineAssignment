#include "laser.h"

CLaser :: CLaser(cocos2d::Layer* layer,float posx,float posy)
{
	index = 0;//default index

	x = posx;
	y = posy;

	m_Sprite = cocos2d::Sprite::create("closedoor.png");
	//m_Sprite->Sprite::setTexture("CloseNormal.png");
	m_Sprite->setScale(0.01f);
	m_Sprite->Sprite::setPosition(Point(x,y));

	auto body = PhysicsBody::createBox(Size(m_Sprite->getContentSize().width/100,m_Sprite->getContentSize().width/100));
	body->setCollisionBitmask(3);
	body->setContactTestBitmask(true);
	body->setDynamic(false);
	m_Sprite->setPhysicsBody(body);;

	Render(x,y);
	layer->addChild(m_Sprite,0);
}

CLaser :: ~CLaser()
{
	
}

void CLaser :: Render(USHORT x, USHORT y)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	float f_posX = visibleSize.width*0.5f + (x - 10) * TileSize * 1.5f;
	float f_posY = visibleSize.height - (y)* TileSize * 1.5f;
	this->m_Sprite->setPosition( Point(f_posX, f_posY) );
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

