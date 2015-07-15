#include "Entity.h"

class CLaser : public CEntity
{
	private:
	int index;//keeps track of which laser to interact with
	public:
	CLaser(cocos2d::Layer* layer,float posx, float posy);
	~CLaser(void);
	int GetIndex();
	void SetIndex(int index);
	void LaserOff();

	void Render(USHORT x, USHORT y);

};