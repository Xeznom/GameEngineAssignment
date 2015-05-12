#ifndef __CPLAYER_H__
#define __CPLAYER_H__

#pragma once

#include "Entity.h"

class CPlayer : public CEntity
{
private:
	static const char* filename;
public:
	CPlayer(void);
	~CPlayer(void);
};

#endif