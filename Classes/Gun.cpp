#include "Gun.h"

const char* CGun::filename = "PortalGun.png";

void CGun::MouseMove (cocos2d::Event* event)
{
	cocos2d::EventMouse* e = (cocos2d::EventMouse*) event;

	float ay = e->getCursorY() + m_Sprite->getPositionY();
	float ax = e->getCursorX() - m_Sprite->getPositionX();
	
	if (ax > 0) //If to face right.
	{
		if (Left) //If facing left
		{
			Offset = 40;
			cocos2d::Point gunloc = Point(m_Sprite->getPositionX()+Offset,m_Sprite->getPositionY());
			m_Sprite->setPosition(gunloc);
			Left = false;
		}
	}
	else //If to face left.
	{
		if (!Left)
		{
			Offset = -40;
			cocos2d::Point gunloc = Point(m_Sprite->getPositionX()+Offset,m_Sprite->getPositionY());
			m_Sprite->setPosition(gunloc);
			Left = true;
		}
	}
	float degrees = CC_RADIANS_TO_DEGREES(atan2(-ay,ax));

	m_Sprite->setRotation(90 + degrees);
}

CGun:: CGun(void)
{
	Offset = 40;
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