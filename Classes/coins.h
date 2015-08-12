#ifndef __CCOIN_H__
#define __CCOIN_H__

#pragma once
#include "Entity.h"

class CCoin : public CEntity
{
private:
	int index;
	Texture2D* empty;
public:
	CCoin(cocos2d::Layer*,const float,const float);
	~CCoin(void);
	inline const int GetIndex() { return index; }
	inline void SetIndex(const int index) { this->index = index; }
	void PickedUp();
	void render(const int,const int);
};
#endif