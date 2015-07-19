#include "coins.h"


CCoin::CCoin(cocos2d::Layer* layer, float posx, float posy)
{
	index = 0;//default index

	x = posx;
	y = posy;

	m_Sprite = cocos2d::Sprite::create("Coin.png");
	//m_Sprite->Sprite::setTexture("CloseNormal.png");
	//m_Sprite->setScale(0.01f);
	m_Sprite->Sprite::setPosition(Point(x,y));

	auto body = PhysicsBody::createBox(Size(m_Sprite->getContentSize().width,m_Sprite->getContentSize().width));
	body->setCollisionBitmask(12);
	body->setContactTestBitmask(true);
	body->setDynamic(false);
	m_Sprite->setPhysicsBody(body);

	render(posx,posy);

	layer->addChild(m_Sprite,0);
	thelayer = layer;
}


CCoin::~CCoin(void)
{
}

void CCoin::PickedUp()
{
	m_Sprite->setTexture(CCTextureCache::getInstance()->addImage("empty.png"));
	//auto body = PhysicsBody::createBox(Size(this->m_Sprite->getContentSize().width/100,this->m_Sprite->getContentSize().width/100));
	//body->setCollisionBitmask(3);
	//body->setContactTestBitmask(true);
	//body->setDynamic(false);
	//m_Sprite->setPhysicsBody(body);
	m_Sprite->getPhysicsBody()->setCollisionBitmask(3);
}

void CCoin::render(USHORT x, USHORT y)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	float f_posX = visibleSize.width*0.5f + (x - 10) * TileSize * 1.5f;
	float f_posY = visibleSize.height - (y)* TileSize * 1.5f;
	this->m_Sprite->setPosition( Point(f_posX, f_posY) );
}

int CCoin :: GetIndex()
{
	return index;
}

void CCoin :: SetIndex(int index)
{
	this->index = index;
}