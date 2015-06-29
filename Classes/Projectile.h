#ifndef __CPROJECTILE_H__
#define __CPROJECTILE_H__

#pragma once

#include "Entity.h"

class CProjectile : public CEntity
{
private:
	static const char* filename[2];
	float speed;
public:
	CProjectile();
	~CProjectile();
	void update(float);
};

#endif