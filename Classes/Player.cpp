#include "Player.h"

const char* CPlayer::filename = "Player.png";

CPlayer::CPlayer(void)
{
	m_Sprite = cocos2d::Sprite::create(filename);

	/*
	Size visibleSize = Director::getInstance()->getVisibleSize();
	float f_posX = (x + 1) * 64;
	//visibleSize.width*0.5f + (x - 5) * 64 + 32; 
	float f_posY = visibleSize.height*0.5f + (y - 4)*64 + 32;
	
	Point newPoint = Point(f_posX,f_posY);
	m_Sprite->setPosition(newPoint);
	*/
}

CPlayer::~CPlayer(void)
{
}
