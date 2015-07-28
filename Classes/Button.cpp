#include "Button.h"


Button::Button(Layer* layer,const float posx,const float posy)
{
	index = 0;//default index

	x = posx; y = posy;

	m_Sprite = cocos2d::Sprite::create("buttonup.png");
	//m_Sprite->Sprite::setTexture("CloseNormal.png");
	m_Sprite->setScale(0.015f);
	m_Sprite->Sprite::setPosition(Point(x,y));

	const Size size = Size(m_Sprite->getContentSize().width * 0.01f, m_Sprite->getContentSize().width * 0.01f);
	PhysicsBody* body = PhysicsBody::createBox(size);
	body->setCollisionBitmask(6);
	body->setContactTestBitmask(true);
	body->setDynamic(false);
	m_Sprite->setPhysicsBody(body);

	render(posx,posy);

	layer->addChild(m_Sprite,0);
	thelayer = layer;
}


Button::~Button(void)
{
}

void Button :: pressed()
{
	m_Sprite->setTexture(CCTextureCache::getInstance()->addImage("buttondown.png"));
	//m_Sprite->setTexture("buttondown.png");
}

void Button::render(const int x,const int y)
{
	const Size visibleSize = Director::getInstance()->getVisibleSize();
	const float f_posX = visibleSize.width*0.5f + (x - 10) * TileSize * 1.5f;
	const float f_posY = visibleSize.height - (y)* TileSize * 1.5f;
	this->m_Sprite->setPosition( Point(f_posX, f_posY) );
}