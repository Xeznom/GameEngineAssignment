#ifndef __SplashScreen__
#define __SplashScreen__

#include <fstream>
#include "cocos2d.h"
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