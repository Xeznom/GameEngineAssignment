#include "Entity.h"

class CTraps : public CEntity
{
	public:
	CTraps(cocos2d::Layer* layer,float posx, float posy);
	~CTraps(void);

	void Render(USHORT x, USHORT y);

};