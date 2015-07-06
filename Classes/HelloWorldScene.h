#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#pragma once

#define MAX_HORIZONTAL 40
#define MAX_VERTICAL 15

#include "cocos2d.h"
#include "Player.h"
#include "Field.h"
#include "Portals.h"
#include "Traps.h"
#include "Enemy.h"
#include "ResourceTable.h"
#include "Door.h"
#include "Button.h"

USING_NS_CC;

const int buttonDoorTotal = 1;

class HelloWorld : public Layer
{
private:
	int tempDMGTimer;
	CField* m_arrayMap[MAX_HORIZONTAL][MAX_VERTICAL];
	CPortals* portals[2];
	CPlayer* player;
	PhysicsWorld* m_world;
	inline void setPhyWorld(PhysicsWorld* world){ m_world = world; }
public:
	Door* theDoors[buttonDoorTotal];
	Button* theButtons[buttonDoorTotal];
	CTraps* Traps;
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

	virtual void update(float);
	virtual void cleanup();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init(); 
	
	void LoadFile(const string mapName);
    
	virtual void onMouseMove (Event*);
	virtual void onMouseDown (Event*);
	virtual void onMouseUp (Event*);
	virtual void onMouseScroll (Event*);

	void teleportaling(int, int);

    // a selector callback
    void menuCloseCallback(Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	bool onContactBegin(PhysicsContact &contact);
};

#endif // __HELLOWORLD_SCENE_H__
