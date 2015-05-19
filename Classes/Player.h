#ifndef __CPLAYER_H__
#define __CPLAYER_H__

#pragma once

#include "Entity.h"

class CPlayer : public CEntity
{
private:
	static const char* filename;

	float x, y;

public:
	CPlayer(void);
	~CPlayer(void);

	void Render();
};

#endif