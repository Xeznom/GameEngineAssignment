#ifndef __SPLASHSCREEN_H__
#define __SPLASHSCREEN_H__

#pragma once

#include <fstream>
#include "HelloWorldScene.h"

USING_NS_CC;

class SplashScreen : public Layer
{
private:
	Sprite * sprite;
public:
	static Scene* createScene();
	virtual bool init();
	void onEnter();
	void FinishSplashScreen(float dt);
	void setFade(bool value);

	CREATE_FUNC(SplashScreen);
};

#endif