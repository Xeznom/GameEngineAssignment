#ifndef __CLASER_H__
#define __CLASER_H__

#pragma once
#include "Entity.h"

class CLaser : public CEntity
{
private:
	int index;//keeps track of which laser to interact with
public:
	CLaser(cocos2d::Layer*,const float,const float);
	~CLaser(void);
	inline const int GetIndex() { return index; }
	inline void SetIndex(const int index) { this->index = index; }
	void LaserOff();

	void Render(const int,const int);
};

#endif