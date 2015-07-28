#ifndef __CDOOR_H__
#define __CDOOR_H__

#pragma once
#include "Entity.h"

class Door : public CEntity
{
private:
	int index;
public:
	Door(cocos2d::Layer*,const float,const float);
	~Door(void);
	inline const int GetIndex() { return index; }
	inline void SetIndex(const int index) { this->index = index; }
	void openDoor();
	void render(const int,const int);
};
#endif