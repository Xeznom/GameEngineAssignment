#include "Button.h"


Button::Button(cocos2d::Layer* layer,float posx, float posy)
{
	
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

	layer->addChild(m_Sprite,0);
}


Button::~Button(void)
{
}
