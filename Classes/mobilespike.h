#include "Entity.h"

class CMobileSpike : public CEntity
{
	private:
	int movementCounter;//track whether its moving up or down
	public:
	CMobileSpike(cocos2d::Layer* layer,float posx, float posy);
	~CMobileSpike(void);
	void changedirection();
	void update(float delta);
	void Render(USHORT x, USHORT y);

};