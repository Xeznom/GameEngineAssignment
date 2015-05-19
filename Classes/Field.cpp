#include "Field.h"


CField::CField(void)
{
	//m_Sprite = NULL;
}


CField::~CField(void)
{

}

void CField::Init(M_TILE_TYPES newType, USHORT x, USHORT y)
{
	tiles = newType;
	m_Sprite = cocos2d::Sprite::create(g_scTileFileName[newType]);
	
	
	//m_Sprite = cocos2d::Sprite::create("white.png");

	Render(x, y);
}

void CField::Render(USHORT x, USHORT y)
{
	//Point orgin = Director::getInstance()->getVisibleOrigin();
	Size visibleSize = Director::getInstance()->getVisibleSize();
	float f_posX = (x+1)*64;
	float f_posY = visibleSize.height/2 - (y-4)*64 + 32;
	m_Sprite->setPosition( Point(f_posX, f_posY) );

}
