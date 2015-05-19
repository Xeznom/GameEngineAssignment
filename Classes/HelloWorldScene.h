#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#pragma once

#define MAX_HORIZONTAL 20
#define MAX_VERTICAL 20

#include "cocos2d.h"
#include "Player.h"
#include "Field.h"

USING_NS_CC;

struct sNode {
	CField* map;
};

class HelloWorld : public cocos2d::Layer
{
private:
	sNode** m_arrayMap;
	
	cocos2d::PhysicsWorld* m_world;
	inline void setPhyWorld(cocos2d::PhysicsWorld* world){ m_world = world; }
public:

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
	virtual void onMouseMove (cocos2d::Event*);
	virtual void onMouseDown (cocos2d::Event*);
	virtual void onMouseUp (cocos2d::Event*);
	virtual void onMouseScroll (cocos2d::Event*);

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
