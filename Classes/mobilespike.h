#ifndef __CMOBILESPIKE_H__
#define __CMOBILESPIKE_H__

#pragma once
#include "Entity.h"

class CMobileSpike : public CEntity
{
private:
	int movementCounter;//track whether its moving up or down
public:
	CMobileSpike(cocos2d::Layer*,const float,const float);
	~CMobileSpike(void);
	void changedirection();
	void update(float delta);
	void Render(const int,const int);
};
#endif