#include "Gem.h"

USING_NS_CC;

cGem::cGem(void)
{
	m_Sprite = NULL;
	m_Action = NULL;
}


cGem::~cGem(void)
{
}


void cGem::Init(E_GEM_TYPES newType, USHORT x, USHORT y)
{
	m_eType = newType;
	m_Sprite = cocos2d::Sprite::create(g_scGemFileName[newType]);

	m_bDrop = false;

	Render(x, y);
}

void cGem::Render(USHORT x, USHORT y)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	float f_posX = (x+1)*64;
	float f_posY = visibleSize.height/2 + (y-4)*64 + 32;
	m_Sprite->setPosition( Point(f_posX, f_posY) );

	m_eState = E_GEM_NORMAL;
}

void cGem::ChangeTexture(E_GEM_TYPES newType)
{
	m_eType = newType;
	m_Sprite->setTexture(g_scGemFileName[m_eType]);
}

void cGem::Update(void)
{
}