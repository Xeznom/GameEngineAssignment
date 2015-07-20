#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#pragma once

#define MAX_HORIZONTAL 40
#define MAX_VERTICAL 15

#include "cocos2d.h"
#include "Player.h"
#include "Field.h"
#include "Portals.h"
#include "spike.h"
#include "Enemy.h"
#include "ResourceTable.h"
#include "Door.h"
#include "Button.h"
#include "HUD.h"
#include "mobilespike.h"
#include "laser.h"
#include "coins.h"

USING_NS_CC;

//const int buttonDoorTotal = 1;//not in use yet/may not even be used

enum G_LAYERING_TYPES
{
	G_BACKGROUND,
	G_GAME,
	G_HUD,
	G_TOTAL
};

class HelloWorld : public Layer
{
private:
	//int buttonCounter;//not in use yet/may not even be used
	//int laserCounter;//not in use yet/may not even be used
	bool firstTimeInit;
	int levelCounter;
	float temp;
	int points;
	float timer;
	//int tempDMGTimer;//not in use yet/may not even be used
	CPortals* portals[2];
	CPlayer* player;
	PhysicsWorld* m_world;
	CField* m_arrayMap[MAX_HORIZONTAL][MAX_VERTICAL];
	CEnemy* enemies;
	inline void setPhyWorld(PhysicsWorld* world){ m_world = world; }
	Point location;
	CMobileSpike * theMobileSpike;
	CCoin * theCoin;
	CLaser * theLaser;
	CHUD* _hud[2];
public:
	void setViewPoint(Vec2 position);
	void loadLevel(void);
	Door* theDoors;
	Button* theButtons;
	//CTraps* Traps;//traps are now cfield since both are static objects and do not require to edit the trap data
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

	virtual void update(float);
	virtual void cleanup();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init(); 
	
	void LoadFile(const string mapName);
	void HUD();
	void despawnObjects();
    
	virtual void onMouseMove (Event*);
	virtual void onMouseDown (Event*);
	virtual void onMouseUp (Event*);
	virtual void onMouseScroll (Event*);

	void teleportaling(int);

    // a selector callback
    void menuCloseCallback(Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	bool onContactBegin(PhysicsContact &contact);
};

#endif // __HELLOWORLD_SCENE_H__
