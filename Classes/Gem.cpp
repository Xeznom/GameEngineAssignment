#include "Gem.h"

USING_NS_CC;

cGem::cGem(void)
{
}


cGem::~cGem(void)
{
}


void cGem::Init(const E_GEM_TYPES newType,const int x,const int y)
{
	m_eType = newType;
	m_Sprite = cocos2d::Sprite::create(g_scGemFileName[newType]);

	m_bDrop = false;

	Render(x, y);
}

void cGem::Render(const int x,const int y)
{
	const Size visibleSize = Director::getInstance()->getVisibleSize();
	const float f_posX = (x+1)*64;
	const float f_posY = visibleSize.height/2 + (y-4)*64 + 32;
	m_Sprite->setPosition( Point(f_posX, f_posY) );

	m_eState = E_GEM_NORMAL;
}

void cGem::ChangeTexture(const E_GEM_TYPES newType)
{
	m_eType = newType;
	m_Sprite->setTexture(g_scGemFileName[m_eType]);
}

void cGem::Update(void)
{
}