#ifndef __CBUTTON_H__
#define __CBUTTON_H__

#pragma once
#include "Entity.h"

class Button : public CEntity
{
private:
	int index;//keeps track to tell which object it interacts with
public:
	Button(Layer*,const float,const float);
	~Button(void);
	inline const int GetIndex() { return index; }
	inline void SetIndex(const int index) { this->index = index; }
	void pressed();
	void render(const int,const int);
};
#endif