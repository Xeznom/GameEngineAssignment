#include "Field.h"


CField::CField(int type, USHORT x, USHORT y)
{
	m_Sprite = cocos2d::Sprite::create(g_scTileFileName[type]);
	Render(x, y);
}

CField::~CField(void)
{
}


void CField::Render(USHORT x, USHORT y)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	float f_posX = visibleSize.width*0.5f + (x - 10) * TILESIZE + TILESIZE/2;
	float f_posY = visibleSize.height - (y)* TILESIZE;
	m_Sprite->setPosition( Point(f_posX, f_posY) );
	
	//sprite Physics
	auto body = PhysicsBody::createCircle(m_Sprite->getContentSize().width/2);
	body->setDynamic(false);
	m_Sprite->setPhysicsBody(body);
}