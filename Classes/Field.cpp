#include "Field.h"


CField::CField(Layer* layer,const int type, const int x, const int y)
{
	tiles = type;
	m_Sprite = cocos2d::Sprite::create(g_scTileFileName[type]);
	layer->addChild(m_Sprite,0);
	thelayer = layer;
	Render(x, y);
}

CField::~CField(void)
{
}

void CField::Render(const int x, const int y)
{
	const Size visibleSize = Director::getInstance()->getVisibleSize();
	const float f_posX = visibleSize.width*0.5f + (x - 10) * TileSize * 1.5f;
	const float f_posY = visibleSize.height - (y)* TileSize * 1.5f;
	this->m_Sprite->setPosition( Point(f_posX, f_posY) );
	
	//sprite Physics
	//future if check
	//check if tile is not empty

	if (tiles != M_EMPTY && tiles != M_ENEMY)
	{
		const Size size = Size(m_Sprite->getContentSize().width, m_Sprite->getContentSize().height);
		PhysicsBody* body = PhysicsBody::createBox(size);
		//PhysicsBody* body = PhysicsBody::createCircle(m_Sprite->getContentSize().width*0.5f);

		if(tiles != M_ENEMY) body->setDynamic(false);

		switch (tiles)
		{
			case M_WHITE://tiles
				body->setCollisionBitmask(5);
				body->setContactTestBitmask(true);
				break;
			case M_DOOR://door
				m_Sprite->setName("door");
				body->setCollisionBitmask(3);
				body->setContactTestBitmask(true);
				break;
			case M_TRAP://traps
				m_Sprite->setName("trap");
				body->setCollisionBitmask(2);
				body->setContactTestBitmask(true);
				break;
			case M_LASER://laser
				body->setCollisionBitmask(10);
				body->setContactTestBitmask(true);
				break;
			case M_COIN://coins
				body->setCollisionBitmask(12);
				body->setContactTestBitmask(true);
				break;
		}
		m_Sprite->setPhysicsBody(body);
	}
}