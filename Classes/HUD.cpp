#include "HUD.h"


CHUD::CHUD()
{
}

CHUD::~CHUD()
{
}

CHUD* CHUD::createHUD(String _message, Point pos)
{
	CHUD* newHUD = new CHUD();

	newHUD->message = Label::createWithTTF(_message.getCString(), "fonts/Marker Felt.ttf", 24);
	newHUD->message->setColor(cocos2d::Color3B(255, 255, 255));
	
	//newHUD->addChild()
	
	newHUD->message->setPosition(pos);


	return newHUD;
}