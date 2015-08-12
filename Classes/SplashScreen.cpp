#include "SplashScreen.h"

USING_NS_CC;

cocos2d::Scene* SplashScreen::createScene()
{
        // 'scene' is an autorelease object
        auto scene = Scene::create();

        // 'layer' is an autorelease object
        auto layer = SplashScreen::create();

        // add layer as a child to scene
        scene->addChild(layer);

        // return the scene
       return scene;
}

bool SplashScreen::init()
{
    if (!Layer::init()) return false;

    auto visibleSize = Director::getInstance()->getVisibleSize();

    sprite = Sprite::create("splash.png");

	sprite->setScale(2.6f);

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width*0.5f , visibleSize.height*0.5f ));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

    return true;
}
void SplashScreen::onEnter()
{
    Layer::onEnter();

	sprite->setOpacity(0);
    CCFadeIn* fadeIn = CCFadeIn::create(1);
    sprite->runAction(fadeIn);
	// Wait for x seconds to load main scene
	this->scheduleOnce(schedule_selector(SplashScreen::FinishSplashScreen), 10.0f);
}

void SplashScreen::FinishSplashScreen(float dt)
{
    // main scene transition
	Director::getInstance()->replaceScene(HelloWorld::createScene());
}