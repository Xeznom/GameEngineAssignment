#include "Gun.h"

const char* CGun::filename = "PortalGun.png";

void CGun::update (float delta){}


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