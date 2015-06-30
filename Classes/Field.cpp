#include "Field.h"


CField::CField(int type, USHORT x, USHORT y)
{
	tiles = type;
	m_Sprite = cocos2d::Sprite::create(g_scTileFileName[type]);
	Render(x, y);
}

CField::~CField(void)
{
}


void CField::Render(USHORT x, USHORT y)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	float f_posX = visibleSize.width*0.5f + (x - 10) * TILESIZE * 1.5;
	float f_posY = visibleSize.height - (y)* TILESIZE * 1.5;
	m_Sprite->setPosition( Point(f_posX, f_posY) );
	
	//sprite Physics
	//future if check
	//check if tile is not empty
	if (tiles != 0)
	{
		auto body = PhysicsBody::createCircle(m_Sprite->getContentSize().width/2);
		body->setDynamic(false);
		m_Sprite->setPhysicsBody(body);
	}
}