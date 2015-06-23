#include "Gun.h"

const char* CGun::filename = "PortalGun.png";

void CGun::update (float delta){}

void CGun::MouseMove (cocos2d::Event* event)
{
	cocos2d::EventMouse* e = (cocos2d::EventMouse*) event;

	float ax = e->getCursorX() - PlayerSprite->getPositionX();
	
	if (ax > 0) //If to face right.
	{
		if (Left) //If facing left
		{
			Offset = 25;
			cocos2d::Point gunloc = Point(m_Sprite->getPositionX()+Offset,m_Sprite->getPositionY());
			m_Sprite->setPosition(gunloc);
			Left = false;
		}
	}
	else //If to face left.
	{
		if (!Left) //If facing right
		{
			Offset = -25;
			cocos2d::Point gunloc = Point(m_Sprite->getPositionX()+Offset,m_Sprite->getPositionY());
			m_Sprite->setPosition(gunloc);
			Left = true;
		}
	}

    Size visibleSize = Director::getInstance()->getVisibleSize();
	float ay = (visibleSize.height + e->getCursorY()) - PlayerSprite->getPositionY();
	//float ay =  e->getCursorY() + PlayerSprite->getPositionY();

	float degrees = CC_RADIANS_TO_DEGREES(atan2(-ay,ax));

	m_Sprite->setRotation(90 + degrees);
}

CGun:: CGun(Sprite* playersprite)
{
	PlayerSprite = playersprite;
	Offset = 30;
	Left = false;
	if (m_Sprite == nullptr)
	{
		m_Sprite = cocos2d::Sprite::create(filename);
		m_Sprite->setScale(0.3f);
	}
}

CGun::~CGun (void)
{

}