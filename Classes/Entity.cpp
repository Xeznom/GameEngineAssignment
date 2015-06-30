#include "Entity.h"

CEntity::CEntity(void) : TileSize(GETVALUE("TileSize"))
{
	m_Sprite = nullptr;
}


CEntity::~CEntity(void)
{
}
