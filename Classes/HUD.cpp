#include "HUD.h"


CHUD::CHUD(String _message, Vec2 pos, int topbottom, int leftright)
{
	this->create();
	message = Label::createWithTTF(_message.getCString(), "fonts/Marker Felt.ttf", 24);

	addChild(message, 2);

	message->setPosition( Vec2 (pos.x + message->getContentSize().width * leftright,
								pos.y - message->getContentSize().height * topbottom));
}

CHUD::~CHUD()
{
}