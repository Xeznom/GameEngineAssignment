#include "Entity.h"

class CSpikes : public CEntity
{
	public:
	CSpikes(cocos2d::Layer* layer,float posx, float posy);
	~CSpikes(void);

	void Render(USHORT x, USHORT y);

};