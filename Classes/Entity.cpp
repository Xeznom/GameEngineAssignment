#include "Entity.h"

CEntity::CEntity(void) : TileSize(GETVALUE("TileSize"))
{
	m_Sprite = nullptr;
	thelayer = nullptr;
}


CEntity::~CEntity(void)
{
	if (thelayer != nullptr && m_Sprite != nullptr)	thelayer->removeChild(m_Sprite);
}
