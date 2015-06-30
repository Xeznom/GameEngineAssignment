#include "Gun.h"

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
	float degrees = CC_RADIANS_TO_DEGREES(atan2(-ay,ax));
	m_Sprite->setRotation(90 + degrees);
}

void CGun::MouseDown(cocos2d::Event* event)
{
	cocos2d::EventMouse* e = (cocos2d::EventMouse*) event;
	int mouseButton = e->getMouseButton();

	switch (mouseButton)
	{
		case 0:
			break;
		default:
			break;
	}
}

CGun::CGun(Layer* layer, const Point loc,const Sprite* playersprite)
{
	PlayerSprite = playersprite;
	Offset = GETVALUE("GunOffset");
	Left = false;

	std::string filename = GETFILE("PortalGun");
	m_Sprite = Sprite::create(filename);
	m_Sprite->setScale(0.3f);

	Point gunloc = Point(loc.x+Offset,loc.y);
	m_Sprite->setPosition(gunloc);
	m_Sprite->setAnchorPoint(Vec2(0.5f,0));

	layer->addChild(m_Sprite,0);
}

CGun::~CGun (void)
{
}