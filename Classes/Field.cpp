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
	float f_posX = visibleSize.width*0.5f + (x - 10) * TileSize * 1.5f;
	float f_posY = visibleSize.height - (y)* TileSize * 1.5f;
	this->m_Sprite->setPosition( Point(f_posX, f_posY) );
	
	//sprite Physics
	//future if check
	//check if tile is not empty
	if (tiles != 0)
	{
		auto body = PhysicsBody::createBox(Size(m_Sprite->getContentSize().width,m_Sprite->getContentSize().height));
		//PhysicsBody* body = PhysicsBody::createCircle(m_Sprite->getContentSize().width*0.5f);
		if(tiles != 4)
		{
			body->setDynamic(false);
		}
		if(tiles == 1)//tiles
		{
			body->setCollisionBitmask(5);
			body->setContactTestBitmask(true);
		}
		//if(tiles == 2)//opendoor
		//{
		//	body->setCollisionBitmask(3);
		//	body->setContactTestBitmask(true);
		//}
		if(tiles == 3)//traps
		{
			body->setCollisionBitmask(2);
			body->setContactTestBitmask(true);
		}
		if(tiles == 4)//enemy?
		{
			body->setCollisionBitmask(3);
			body->setContactTestBitmask(true);
		}
		//if(tiles == 5)//closedoor
		//{
		//	body->setCollisionBitmask(5);
		//	body->setContactTestBitmask(true);
		//}
		m_Sprite->setPhysicsBody(body);
	}
}